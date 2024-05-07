#include <stdlib.h>
#include <string.h>

void merge(int a[], int na, int b[], int nb, int c[]) {
    int ia, ib, ic;
    for(ia = ib = ic = 0; (ia < na) && (ib < nb); ic++) {
        if (a[ia] < b[ib]) {
            c[ic] = a[ia];
            ia++;
        } else {
            c[ic] = b[ib];
            ib++;
        }
    }
    for (; ia < na; ia++, ic++) {
        c[ic] = a[ia];
    }
    for (; ib < nb; ib++, ic++) {
        c[ic] = b[ib];
    }
}

void merge_sort(int arr[], int n) {
    int len, *temp_arr, *base;
    temp_arr = (int*) malloc(sizeof(int) * n);
    for (len = 1; len < n; len *= 2) {
        for (base = arr; base < arr + n; base += 2 * len) {
            merge(base, len, base + len, len, temp_arr);
            memcpy(base, temp_arr, 2 * len * sizeof(int));
        }
    }
}
