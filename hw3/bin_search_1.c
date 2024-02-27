#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*******************************Defines****************************************/
#define ARR_MAX_LENGTH 50

/***************************Function declarations******************************/
/**
 * @fn search_shift_arr
 * @brief Return the index of 'target' in the shifted array arr.
 * @param arr - Shifted array of uniq integers.
 * @param n - Length of arr.
 * @param target - Number to find.
 * @return - Index of target, or -1 if target doesnt in the array.
 * @note Shifted array is sorted array in which an unknown number of its last
 * elements have been flipped be first.
 * @note Time complex is O(log(n)).
 */
int search_shift_arr(int arr[], int n, int target);

/*************************Put functions declarations here**********************/


/******************************************************************************/


int main(void) {
    int arr[ARR_MAX_LENGTH] = {0};
    int n = 0;
    int target = 0;

    printf("Please enter array length:\n");
    scanf("%d",&n);
    printf("Please enter target number:\n");
    scanf("%d",&target);
    printf("Please enter shifted array:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    printf("%d\n",search_shift_arr(arr,n,target));
    return 0;
}

/*************************Functions implementations****************************/
int search_shift_arr(int arr[], int n, int target) {
    n = n - 1; //n would be the max in the binary search
    int min = 0, current = n / 2; //0 is the min, current is in the middle
    if (arr[n] == target) {//assume that n is not the target
        return n;
    }
    while (n > min) {
        if (arr[current] == target) { //check if we found the target
            return current;
        }
        if (arr[current] > target) { //check where the target is
            n = current; //move the max
        } else {
            min = current; //move the min
        }
        current = (min + n) / 2; //update the current
    }
    return -1; //we didn't find the target
}
