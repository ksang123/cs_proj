#include <stdio.h>

void print_arr(int x[], int idx) {
    for (int i = 0; i < idx; i++) {
        printf("%d, ", x[i]);
    }
    printf("\n");
}

int printSolution(int a[], int n, int b, int idx, int x[]) {
    if (idx == n) {
        if (b == 0) {
            print_arr(x, idx);
            return 0;
        }
        return -1;
    }
    int sol = -1;
    for(int i = 0; i <= b / a[idx]; i++) {
        x[idx] = i;
        if (!printSolution(a, n, b - x[idx] * a[idx], idx + 1, x)) {
            sol = 0;
        }
    }
    return sol;
}


int main(void) {
    int a[] = {3, 4, 6, 2};
    int x[4] = {0};
    printf("%d\n", printSolution(a, 4, 26, 0, x));
    return 0;
}
