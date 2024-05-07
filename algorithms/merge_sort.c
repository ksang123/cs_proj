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

void internal_msort(int a[], int n, int helper_array[]) {
    int left = n / 2, right = n - left;
    if (n < 2) {
        return;
    }
    internal_msort(a, left, helper_array);
    internal_msort(a + left, right, helper_array);
    merge(a, left, a + left, right, helper_array);
    memcpy(a, helper_array, n * sizeof(int));
}

void merge_sort(int a[], int n) {
    int *tmp_array = (int*) malloc(sizeof(int) * n);
    internal_msort(a, n, tmp_array);
    free(tmp_array);
}
