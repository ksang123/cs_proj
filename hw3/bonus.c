#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10
#define MAX_STRING_LEN 100

void add_contact(char first_names[]
[MAX_STRING_LEN], char last_names[][MAX_STRING_LEN], char emails[]
[MAX_STRING_LEN], char phone_numbers[][MAX_STRING_LEN], int *num_contacts);
void remove_contact(char first_names[]
[MAX_STRING_LEN], char last_names[][MAX_STRING_LEN], char emails[]
[MAX_STRING_LEN], char phone_numbers[][MAX_STRING_LEN], int *num_contacts);
void search_contact(char first_names[][MAX_STRING_LEN], char last_names[]
[MAX_STRING_LEN], char emails[][MAX_STRING_LEN], char phone_numbers[]
[MAX_STRING_LEN], int num_contacts);
void print_all_contacts(char first_names[][MAX_STRING_LEN], char last_names[]
[MAX_STRING_LEN], char emails[][MAX_STRING_LEN], char phone_numbers[]
[MAX_STRING_LEN], int num_contacts);

int main(void) {
    char first_names[MAX_CONTACTS][MAX_STRING_LEN];
    char last_names[MAX_CONTACTS][MAX_STRING_LEN];
    char emails[MAX_CONTACTS][MAX_STRING_LEN];
    char phone_numbers[MAX_CONTACTS][MAX_STRING_LEN];
    int num_contacts = 0;
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Search Contact\n");
        printf("4. Print All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(first_names, last_names, emails,
                            phone_numbers, &num_contacts);
                break;
            case 2:
                remove_contact(first_names, last_names, emails,
                               phone_numbers, &num_contacts);
                break;
            case 3:
                search_contact(first_names, last_names, emails,
                               phone_numbers, num_contacts);
                break;
            case 4:
                print_all_contacts(first_names, last_names, emails,
                                   phone_numbers, num_contacts);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void add_contact(char first_names[][MAX_STRING_LEN], char last_names[]
[MAX_STRING_LEN], char emails[][MAX_STRING_LEN], char phone_numbers[]
[MAX_STRING_LEN], int *num_contacts) {
    if (*num_contacts >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    printf("Enter First Name: ");
    scanf("%s", first_names[*num_contacts]);
    printf("Enter Family Name: ");
    scanf("%s", last_names[*num_contacts]);
    printf("Enter phone number: ");
    scanf("%s", phone_numbers[*num_contacts]);
    printf("Enter email: ");
    scanf("%s", emails[*num_contacts]);

    printf("Contact added successfully.\n");
    (*num_contacts)++;
}

void remove_contact(char first_names[][MAX_STRING_LEN], char last_names[]
[MAX_STRING_LEN], char emails[][MAX_STRING_LEN], char phone_numbers[]
[MAX_STRING_LEN], int *num_contacts) {
    char first_name[MAX_STRING_LEN];
    char last_name[MAX_STRING_LEN];
    printf("Enter First Name to remove: ");
    scanf("%s", first_name);
    printf("Enter Family Name to remove: ");
    scanf("%s", last_name);

    int index = -1;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(first_name, first_names[i]) == 0 &&
        strcmp(last_name, last_names[i]) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        char tmp_first_names[MAX_STRING_LEN][MAX_STRING_LEN];
        char tmp_last_names[MAX_STRING_LEN][MAX_STRING_LEN];
        char tmp_emails[MAX_STRING_LEN][MAX_STRING_LEN];
        char tmp_phone_numbers[MAX_STRING_LEN][MAX_STRING_LEN];

        for (int i = 0; i < index; i++) {
            snprintf(tmp_first_names[i],
                     MAX_STRING_LEN, "%s", first_names[i]);
            snprintf(tmp_last_names[i],
                     MAX_STRING_LEN, "%s", last_names[i]);
            snprintf(tmp_emails[i],
                     MAX_STRING_LEN, "%s", emails[i]);
            snprintf(tmp_phone_numbers[i],
                     MAX_STRING_LEN, "%s", phone_numbers[i]);
        }

        for (int i = index; i < *num_contacts - 1; i++) {
            snprintf(tmp_first_names[i],
                     MAX_STRING_LEN, "%s", first_names[i + 1]);
            snprintf(tmp_last_names[i],
                     MAX_STRING_LEN, "%s", last_names[i + 1]);
            snprintf(tmp_emails[i],
                     MAX_STRING_LEN, "%s", emails[i + 1]);
            snprintf(tmp_phone_numbers[i],
                     MAX_STRING_LEN, "%s", phone_numbers[i + 1]);
        }

        for (int i = 0; i < *num_contacts - 1; i++) {
            snprintf(first_names[i],
                     MAX_STRING_LEN, "%s", tmp_first_names[i]);
            snprintf(last_names[i],
                     MAX_STRING_LEN, "%s", tmp_last_names[i]);
            snprintf(emails[i],
                     MAX_STRING_LEN, "%s", tmp_emails[i]);
            snprintf(phone_numbers[i],
                     MAX_STRING_LEN, "%s", tmp_phone_numbers[i]);
        }

        (*num_contacts)--;
        printf("Contact removed successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}


void search_contact(char first_names[][MAX_STRING_LEN], char last_names[]
[MAX_STRING_LEN], char emails[][MAX_STRING_LEN], char phone_numbers[]
[MAX_STRING_LEN], int num_contacts) {
    char first_name[MAX_STRING_LEN];
    char last_name[MAX_STRING_LEN];
    printf("Enter First Name to search: ");
    scanf("%s", first_name);
    printf("Enter Family Name to search: ");
    scanf("%s", last_name);

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(first_name, first_names[i]) == 0 &&
        strcmp(last_name, last_names[i]) == 0) {
            printf("First Name: %s\n", first_names[i]);
            printf("Family Name: %s\n", last_names[i]);
            printf("Phone Number: %s\n", phone_numbers[i]);
            printf("Email: %s\n", emails[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void print_all_contacts(char first_names[][MAX_STRING_LEN], char last_names[]
[MAX_STRING_LEN], char emails[][MAX_STRING_LEN], char phone_numbers[]
[MAX_STRING_LEN], int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("All Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("First Name: %s\n", first_names[i]);
        printf("Family Name: %s\n", last_names[i]);
        printf("Phone Number: %s\n", phone_numbers[i]);
        printf("Email: %s\n\n", emails[i]);
    }
}
