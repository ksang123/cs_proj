#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* one2twenty[] = {
        "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
};
const char* tens[] = {
        "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
        "Ninety"
};

char* int2string(int num) {
    // Allocate memory for the result string
    char* result = (char*)malloc(100);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    if (num == 0) {
        strcpy(result, "");
    } else if (num < 20) {
        sprintf(result, "%s ", one2twenty[num - 1]);
    } else if (num < 100) {
        sprintf(result, "%s %s", tens[num / 10 - 2], int2string(num % 10));
    } else if (num < 1000) {
        sprintf(result, "%s Hundred %s", one2twenty[num / 100 - 1], int2string(num % 100));
    } else {
        sprintf(result, "%s Thousand %s", one2twenty[num / 1000 - 1], int2string(num % 1000));
    }

    return result;
}

int main(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 1 || num > 9999) {
        printf("Number out of range (1-9999).\n");
        return 1;
    }
    char* result = int2string(num);
    printf("%s\n", result);
    free(result);  // Free the dynamically allocated memory
    return 0;
}
