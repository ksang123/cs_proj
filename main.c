#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void merge(int* arr, int l, int m, int r) {

}

void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    int n = 0;
    scanf("%d",&n);
    int* arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr, 0, n);
    for (int i = 0; i < n; ++i) {
        printf("%d, ", arr[i]);
    }
    free(arr);
    return 0;
}
