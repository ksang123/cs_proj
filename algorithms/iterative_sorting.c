#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//Max-Sort O(n^2)
int get_max(int a[], int n) {
    int i, i_max = 0;
    for (i = 1; i < n; ++i) {
        if (a[i] > a[i_max]) {
            i_max = i;
        }
    }
     return i_max;
}

void max_sort(int a[], int n) {
    int length;
    for (length = n; length > 1; --length) {
        int i_max = get_max(a, length);
        swap(&a[length-1], &a[i_max]);
    }
}

//Bubble-Sort O(n^2)
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void merge(int a[], int na, int b[], int nb, int c[]) {
    int ia = 0, ib = 0, ic = 0;
    while (ia < na && ib < nb) {
        if (a[ia] < b[ib]) {
            c[ic] = a[ia];
            ia++;
        } else {
            c[ic] = b[ib];
            ib++;
        }
    }
    while (ia < na) {
        c[ic++] = a[ia++];
    }
    while (ib < nb) {
        c[ic++] = b[ib++];
    }
}

//Merge-Sort O(n*log(n))
int merge_sort(int arr[], int n) {
    int len;
    int *temp_array, *base;

    temp_array = (int*)malloc(sizeof(int)*n);
    if (temp_array == NULL) {
        printf("dynamic allocation error in merge_sort");
        return 1;
    }
    for (len = 1; len < n; len *= 2) {
        for (base = arr; base < arr + n; base += 2 * len) {
            merge(base, len, base + len, len, temp_array);
            memcpy(base, temp_array, 2 * len * sizeof(int));
        }
    }
    free(temp_array);
    return 0;
}
