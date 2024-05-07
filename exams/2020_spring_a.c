#include <string.h>

int FindFixedPoint(int a[], int n) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (a[mid] == mid) {
            return mid;
        }
        if (a[mid] > mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void swap(char *p1, char *p2) {
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void reverse_words(char *str) {
    //reverse entire string then reverse the words themselves
}
