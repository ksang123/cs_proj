#include <stdio.h>

int find_mistake(int dist[], int n) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid == 0) {
            low += 1;
        } else {
            if (dist[mid - 1] < dist[mid]) {
                return mid;
            }
            if (dist[mid] > dist[high]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    int a[] = {20, 19, 18, 17, 16, 15, 21, 19, 21};
    printf("%d\n", find_mistake(a, 9));
    return 0;
}
