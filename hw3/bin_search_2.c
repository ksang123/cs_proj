#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*******************************Defines****************************************/
#define ARR_MAX_LENGTH 50


/***************************Function declarations******************************/
/**
 * @fn k_closest_to_target
 * @brief Return the value of the k closest number to target in 'arr'.
 * @param arr - Sorted array of uniq integers.
 * @param n - Length of arr.
 * @param target - Integer number.
 * @param k - A non-negative number.
 * @return - value of kth closest to target.
 * @note If 2 different numbers are at the same distance from target we'll
 * treat the smaller one to be closer to target.
 * @note We assume k <= n.
 * @note Time complex is O(log(n) + k).
 */
int k_closest_to_target(int arr[], int n, int target, int k);

int binary_search(int arr[], int n, int target);
/*************************Put functions declarations here**********************/


/******************************************************************************/


int main(void) {
    int arr[ARR_MAX_LENGTH] = { 0 };
    int n =                     0;
    int target =                0;
    int k =                     0;

    printf("Please enter array length:\n");
    scanf("%d",&n);
    printf("Please enter target number:\n");
    scanf("%d",&target);
    printf("Please enter k:\n");
    scanf("%d",&k);
    printf("Please enter sorted and uniq array:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    printf("%d\n",k_closest_to_target(arr,n,target,k));
    return 0;
}

/*************************Functions implementations****************************/
int k_closest_to_target(int arr[], int n, int target, int k) {
    int index = binary_search(arr, n, target);
    //printf("%d\n", arr[index]);
    int left = index; //find the index of target
    int right = index;
    for (int i = 1; i < k; i++) {
        if (left <= 0) {
            return arr[right + k - i];
        } else if (right >= n-1) {
            return arr[left - k + i];
        } else if (arr[right] - target < target - arr[left]) {
            right++;
        } else {
            left--;
        }
    }
    return arr[left] > arr[right] ? arr[right] : arr[left];
}

int binary_search(int arr[], int n, int target) {
    int max = n - 1; //n would be the max in the binary search
    int min = 0, current = max / 2; //0 is the min, current is in the middle
    while (max >= min) {
        current = (min + max) / 2;
        if (arr[current] == target) {
            return current;
        }
        if (arr[current] < target) { //check where the target is
            min = current + 1;
        } else {
            max = current - 1;
        }
    }
    //we didn't find the target, return the closest to target
    return n <= min + 1 ? min - 1:
    target - arr[min] < arr[min+1] - target ? min : min + 1;
}
