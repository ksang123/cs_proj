#include <stdio.h>

void swap(char* p1, char* p2) {
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int weight(char* s) {
    int w = 0;
    while (*s) {
        w += *s;
        s++;
    }
    return w;
}

void q3(char* s[], int n) {
    int k = 0;
    for (int w = 0; w <= 10*127; w++) {
        for(int i = 0; i < n; i++) {
            if(weight(s[i]) == w) {
                swap(s[k], s[i]);
                k++;
            }
        }
    }
}

int main(void) {
    char* arr[] = {"100", "53", "0", "0000"};
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    q3(arr, arr_length);
    for (int i = 0; i < arr_length; i++) {
        printf("%s\n", arr[i]);
    }
    return 0;
}
