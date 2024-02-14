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
    int longest_len = 0, longest_index = -1;
    //the index and length of the longest sequence
    int current_len = 0, last_even = -1, starting_index = 0;
    //the len of the current sequence,
    //the last even number and the starting index of the sequence
    for(int i = 0; i < len; i++) {//go through every item on the array
        //check if the item qualifies for the sequence
        if (arr[i] % 2 == 0 &&
            (arr[i] - 2 == last_even || last_even == -1)) {
            current_len++;//add the item to the sequence
            last_even = arr[i];
        } else {
            //sequence ended
            if (current_len > longest_len) {
                //check if it's the biggest sequence yet
                longest_len = current_len;
                longest_index = starting_index;
            }
            //reset variables for new sequence
            if (arr[i] % 2 == 0) {
                current_len = 1;
                last_even = arr[i];
                starting_index = i;
            } else {
                current_len = 0;
                last_even = -1;
                starting_index = i + 1;
            }
        }
    }
    if (current_len > longest_len) {//if the sequence ended on the last item
        longest_len = current_len;
        longest_index = starting_index;
    }
    print_longest_sequence(arr, longest_index, longest_len);
}

void print_longest_sequence(int arr[], int index, int len) {
    //this function prints the longest sequence in the array
    if (index == -1 || len == 0) {//check if a sequence exists
        printf("No even sequence in the array\n");
        return;
    }
    printf("The longest sequence with continuous even numbers is:");
    for (int i = index; i < index + len; i++) {//print the sequence
        printf(" %d", arr[i]);
    }
}
