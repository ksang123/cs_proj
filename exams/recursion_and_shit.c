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
    movewhite(to, from);
    hawaii1(m-1, via, from);
    movered(via, to);
}
