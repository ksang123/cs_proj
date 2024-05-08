int compress(int a[], int n) {
    int counter = 0, len = 1, last = a[0];
    for (int i = 1; i < n; i++) {
        while (i < n && a[i] == last) {
            a[len] = a[i];
            counter++;
            i++;
            len++;
        }
        if (i < n && a[i] != last) {
            last = a[i];
            if (counter >= 2) {
                len -= (counter + 1);
                a[len] = -counter - 1;
                for (int j = 2; j < counter + 1; j++) {
                    a[len] = a[i - counter + j];
                    len++;
                }
            }
            len++;
            counter = 0;
        }
    }
    return len;
}