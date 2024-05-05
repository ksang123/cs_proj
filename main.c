#include <stdbool.h>
#include <stdio.h>

bool q2(int arr[], int n, int min, int max);
int search(int arr[], int n, int target);

int main(void) {
    int arr[] = {1,3,4,5,7,9,10};
    printf("%d",q2(arr, 7, 3, 5));
    return 0;
}

bool q2(int arr[], int n, int min, int max) {
    int start = search(arr, n, min);
    if (start == -1) {
        return false;
    }
    return arr[start + min - max + 1] == max;
}

int search(int arr[], int n, int target) {
    int low = 0, mid, high = n-1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return -1;
}
