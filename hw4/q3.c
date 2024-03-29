#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//swaps 2 indexes
void swap(char str[], int idx1, int idx2) {
    char temp = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = temp;
}

//recursive function that checks if str1 is a permutation of str2
bool is_perm(char str1[], char str2[], int n) {
    if (strcmp(str1, str2) == 0) {
        return true;
    }
    if (n == 0) {
        return false;
    }
    for (int i = 0; i <= n; i++) {
        if (n % 2 == 0) {
            swap(str1, 0, n);
        } else {
            swap(str1, i, n);
        }
        if (is_perm(str1, str2, n-1)) {
            return true;
        }
    }
    return false;
}

//assume that the length is equal
bool isPermutation(char str1[], char str2[]) {
    int len1 = (int)strlen(str1), len2 = (int)strlen(str2);
    if (len1 != len2) {
        return false;
    }
    bool is_permutation = is_perm(str1, str2, len1-1);
    return is_permutation;
}

int main(void) {
    char str1[100], str2[100], str3[100];

    scanf("%s", str1);

    scanf("%s", str2);

    snprintf(str3, sizeof(str3), "%s", str1);

    if (isPermutation(str1, str2))
        printf("Yes, '%s' is a permutation of '%s'.\n", str3, str2);
    else
        printf("No, '%s' is not a permutation of '%s'.\n", str3, str2);

    return 0;
}
