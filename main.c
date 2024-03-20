#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void swap(char str[], int idx1, int idx2) {
    char temp = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = temp;
}

bool is_perm(char str1[], char str2[], int n, char or[]) {
    if (strcmp(str1, str2) == 0) {
        return true;
    }
    if (n == 0) {
        return false;
    }
    snprintf(or, strlen(str1)+1, "%s", str1);
    for (int i = 0; i <= n; i++) {
        swap(str1, i, n);
        if (is_perm(str1, str2, n-1, or)) {
            snprintf(str1, strlen(str1)+1, "%s", or);
            return true;
        }
        snprintf(str1, strlen(str1)+1, "%s", or);
    }
    return false;
}

bool isPermutation(char str1[], char str2[]) {
    int len1 = (int)strlen(str1), len2 = (int)strlen(str2);
    if (len1 != len2) {
        return false;
    }
    char* str = (char*) malloc(sizeof(char) * strlen(str1));
    bool is_permutation = is_perm(str1, str2, len1-1, str);
    free(str);
    return is_permutation;
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
