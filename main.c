#include <stdio.h>
#include <stdlib.h>

void longestContinuousEvenSequence(int arr[], int len);
void print_longest_sequence(int arr[], int index, int len);

int main(void) {
    int len_array = 0;
    // First enter the size of the array
    scanf("%d", &len_array);
    // allocating the array - will be explained later in the course
    int* arr = malloc(sizeof(int) * len_array);
    if(arr) {
        // Enter the numbers that the array will hold
        for (int start_index = 0; start_index < len_array; start_index++) {
            scanf("%d", &(arr[start_index]));
        }
        longestContinuousEvenSequence(arr, len_array);
    }
    // Freeing the array - will be explained later in the course
    free(arr);
    return 0;
}

void longestContinuousEvenSequence(int arr[], int len) {
    int longest_len = 0, current_even = 0, longest_index = -1,
    current_len = 0, current_index = 0;
    for (int i = 0; i < len; i++) {
        printf("%d", current_len);  
        if (arr[i] % 2 == 0 &&
        (arr[i] + 2 == current_even || current_even == 0)) {
            current_len++;
            current_even = arr[i];
        } else {
            if (current_len > longest_len) {
                longest_index = current_index;
                longest_len = current_len;
            }
            current_even = 0;
            current_len = 0;
            current_index = i;
        }
    }
    print_longest_sequence(arr, longest_index, longest_len);
}

void print_longest_sequence(int arr[], int index, int len) {
    if (index == -1 || len == 0) {
        printf("No even sequence in the array\n");
        return;
    }
    printf("The longest sequence with continuous even numbers is:");
    for (int i = index; i < index + len; i++) {
        printf(" %d", arr[i]);
    }
}
