#include <string.h>

int FindOddOccuring(int arr[], int n) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (mid % 2 == 0 && arr[mid] != arr[mid + 1]) {
            return arr[mid] == arr[mid - 1] ? mid + 1 : mid;
        }
        if (mid % 2 == 1 && arr[mid] != arr[mid - 1]) {
            return arr[mid] == arr[mid + 1] ? mid - 1 : mid;
        }
        if ((mid - low) % 2 == 1) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void CycleShift(int arr[], int n, int k) {
    int extra;
    for (int i = 0; i < k; i++) {
        extra = arr[n - k + i];
        for (int j = 0; j < n / k; j++) {
            arr[n - j * k + i] = arr[n - (j - 1) * k + i];
        }
        arr[k - i] = extra;
    }
}

int search_max(char *str, int n, char c) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (mid > n - 1) {
            mid -= 1;
        }
        if (str[mid] == c && (mid == n - 1 || str[mid + 1] != c)) {
            return mid;
        }
        if ((str[mid] == c && str[mid + 1] == c) || str[mid] < c) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int search_min(char *str, int n, char c) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (str[mid] == c && (mid == 0 || str[mid - 1] != c)) {
            return mid;
        }
        if ((str[mid] == c && str[mid - 1] == c) || str[mid] > c) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int CountChars(char *str, int n, char c) {
    int max = search_max(str, n, c);
    int min = search_min(str, n, c);
    if (max == -1 || min == -1) {
        return 0;
    }
    return max - min + 1;
}



int IsConstructible(int numbers[],int n, int result) {
    if (n == 0) {
        if (result == 0) {
            return 1;
        }
        return 0;
    }
    int flag = 0;
    flag += IsConstructible(numbers + 1, n - 1, result - numbers[0]);
    flag += IsConstructible(numbers + 1, n - 1, result + numbers[0]);
    return flag;
}
