#include <stdio.h>
#include <malloc.h>
#include <math.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    double z1 = 0;
    double z2 = 1;
    for(int i = 1; i <= numsSize; i++) {
        z1 += i;
        z1 -= nums[i-1];
        z2 /= i;
        z2 *= nums[i-1];
    }
    int* ret = malloc(2 * sizeof(int));
    ret[0] = (int)round(z1 * z2 / (1 - z2));
    ret[1] = (int)round(z1 / (1 - z2));
    return ret;
}

int main(void) {
    int arr[] = {37,62,43,27,12,66,36,18,39,54,61,65,47,32,23,2,46,8,4,24,29,38,63,39,25,11,45,28,44,52,15,30,21,7,57,49,1,59,58,14,9,40,3,42,56,31,20,41,22,50,13,33,6,10,16,64,53,51,19,17,48,26,34,60,35,5};
    int return_size[] = {0, 0};
    int *arr1 = findErrorNums(arr, sizeof(arr)/sizeof(arr[0]), return_size);
    printf("answer: %d, %d\n", arr1[0], arr1[1]);
    free(arr1);
    return 0;
}
