int search(int arr[], int n, int x) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int count_pairs(int hist[], int num) {
    int count = 0;
    for (int s1 = 0; s1 <= num; s1++) {
        int s2 = num - s1;
        if (s2 > 200) {
            continue;
        }
        if (hist[s1] == 0 || hist[s2] == 0 || s1 > s2) {
            continue;
        }
        if (s1 == s2) {
            count += hist[s1] * (hist[s1] - 1) / 2;
        } else {
            count += hist[s1] * hist[s2];
        }
    }
    return count;
}

int q3(int points[], int n) {
    int hist[200] = {0};
    for (int i = 0; i < n; i++) {
        hist[points[i]]++;
    }
    int max_count = 0;
    int magic_num = -1;
    for (int num = 0; num <= 400; num++) {
        int count = count_pairs(hist, num);
        if (max_count < count) {
            max_count = count;
            magic_num = num;
        }
    }
    return magic_num;
}
