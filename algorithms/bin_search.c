int search(int arr[], int n, int target) {
    int low = 0, mid, high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
