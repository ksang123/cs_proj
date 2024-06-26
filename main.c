#include <stdio.h>
#define LETTERS 'z' - 'a' + 1

int rearrangeStringToPalindrome(char* str) {
    int hist[LETTERS] = { 0 }, counter = 0;
    while (*str) {
        hist[*str - 'a']++;
        counter++;
        str++;
    }
    int mercy = (counter % 2 == 0) ? 0 : 1;
    for (int i = 0; i < LETTERS; i++) {
        if (hist[i] % 2 != 0) {
            mercy--;
        }
    }
    return mercy >= 0;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    char str[] = "hellohello";
    int res = rearrangeStringToPalindrome(str);
    printf("%d\n", res);
    return 0;
}