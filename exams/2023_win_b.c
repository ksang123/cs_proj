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
