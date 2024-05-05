#include <string.h>

int main(void) {
    return 0;
}

int q2(char* arr[], int n) {
    int low = 0, mid, high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid - 1 >= 0 && strlen(arr[mid]) > strlen(arr[mid-1])) {
            return mid;
        }
        if (mid + 1 < n && strlen(arr[mid + 1]) > strlen(arr[mid])) {
            return mid + 1;
        }
        if (strlen(arr[mid]) < strlen(arr[low])) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return 0;
}


void q3(int array[], int n) {
    //merge sort and compare array to
}
