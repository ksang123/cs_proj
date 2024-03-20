#include <stdio.h>
#include <stdbool.h>

bool isPermutation(char str1[], char str2[]) {
    return false;
}

int main(void) {
    char str1[100], str2[100];

    scanf("%s", str1);

    scanf("%s", str2);

    if (isPermutation(str1, str2))
        printf("Yes, '%s' is a permutation of '%s'.\n", str1, str2);
    else
        printf("No, '%s' is not a permutation of '%s'.\n", str1, str2);

    return 0;
}
