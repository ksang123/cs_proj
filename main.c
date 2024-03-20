#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char* swap(char str[], int idx1, int idx2) {
    char* str1 = (char*) malloc(sizeof(char) * strlen(str));
    strcpy(str1, str);
    char temp = str1[idx1];
    str1[idx1] = str1[idx2];
    str1[idx2] = temp;
    return str1;
}

bool is_perm(char str1[], char str2[], int n) {
    if (strcmp(str1, str2) == 0) {
        return true;
    }
    if (n == 0) {
        return false;
    }
    for (int i = 0; i <= n; i++) {
        if (is_perm(swap(str1, i, n), str2, n-1)) {
            return true;
        }
    }
    return false;
}

bool isPermutation(char str1[], char str2[]) {
    int len1 = (int)strlen(str1), len2 = (int)strlen(str2);
    if (len1 != len2) {
        return false;
    }
    return is_perm(str1, str2, len1-1);
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
