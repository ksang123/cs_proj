#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void merge(int* arr, int r, int l) {

}

void merge_sort(int* arr, int r, int l) {
    
}

int main(void) {
    int n = 0;
    printf("Please enter array length:\n");
    scanf("%d",&n);
    int* arr = (int *) malloc(n * sizeof(int));
    printf("Please enter shifted array:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr, 0, n);
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}
