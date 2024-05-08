#include <stdio.h>

int IsConstructible(int numbers[],int n, int result) {
    if (n == 0) {
        if (result == 0) {
            return 1;
        }
        return 0;
    }
    int flag = 0;
    flag += IsConstructible(numbers + 1, n - 1, result - numbers[0]);
    flag += IsConstructible(numbers + 1, n - 1, result + numbers[0]);
    return flag;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int a[] = {8, 8, 8, 7};
    printf("%d\n", IsConstructible(a, 4, 1));
    return 0;
}