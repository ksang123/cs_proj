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


int main(void) {
    hawaii2(2, 1, 3);
    return 0;
}
