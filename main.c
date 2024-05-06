#include <stdio.h>

int q2(double arr[], int n) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid < 1) {
            low = mid + 1;
        } else {
            if (arr[mid - 1] <= 0 && arr[mid] > 0) {
                return mid;
            }
            if (arr[mid] <= 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}



int main(void) {
    double arr[] = {-6.6, -1, -2.5, 0.01};
    printf("%d", q2(arr, 4));
    return 0;
}

