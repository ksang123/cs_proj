int find_mistake(int dist[], int n) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid == 0) {
            low += 1;
        } else {
            if (dist[mid - 1] < dist[mid]) {
                return mid - 1;
            }
            if (dist[mid] > dist[high]) {
                high = mid - 1;
            } else {
                low = mid - 1;
            }
        }
    }
    return -1;
}