#include <string.h>
#include <stdlib.h>

//Merge-Sort O(n*log(n))
//place- O(n)
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
