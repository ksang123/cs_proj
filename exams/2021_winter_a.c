#define LETTERS 'z' - 'a' + 1

int index_of_equal(int a[], int n) {
    int after = 0, b4 = 0;
    for (int i = 0; i < n; i++) {
        after += a[i];
    }
    for (int i = 0; i < n; i++) {
        if (b4 == after - a[i]) {
            return i;
        }
        after -= a[i];
        b4 += a[i];
    }
    return -1;
}

int rearrangeStringToPalindrome(char* str) {
    int hist[LETTERS] = { 0 }, counter = 0;
    while (*str) {
        hist[*str - 'a']++;
        counter++;
        str++;
    }
    int mercy = (counter % 2 == 0) ? 0 : 1;
    for (int i = 0; i < LETTERS; i++) {
        if (hist[i] % 2 != 0) {
            mercy--;
        }
    }
    return mercy >= 0;
}

int is_partition_possible(int arr[], int n) {

}