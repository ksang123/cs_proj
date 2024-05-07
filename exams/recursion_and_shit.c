#include <stdio.h>

void movered(int from, int to) {
    printf("move red ring from %d to %d\n", from, to);
}

void movewhite(int from, int to) {
    printf("move white ring from %d to %d\n", from, to);
}

void hawaii1(int m, int from, int to) {
    if (m == 0) {
        return;
    }
    int via = 6 - from - to;
    hawaii1(m-1, from, to);
    movered(from, via);
    hawaii1(m-1, to, via);
    movewhite(from, to);
    hawaii1(m-1, via, from);
    movered(via, to);
    hawaii1(m-1, from, to);
}

void hawaii2(int m, int from, int to) {
    if (m == 0) {
        return;
    }
    int via = 6 - from - to;
    hawaii1(m - 1, from, to);
    movered(from, via);
    hawaii1(m - 1, to, via);
    movewhite(from, to);
    hawaii1(m - 1, via, to);
    movered(via, from);
    hawaii1(m - 1, to, from);
    hawaii2(m - 1, from, to);
}

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
