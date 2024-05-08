#include <stdio.h>
#define M 5
#define N 5
#define DIFF ('A' - 'a')

int is_legal(int i, int j) {
    return !(i < 0 || j < 0 || i >= M || j >= N);
}

int aux(char letters[M][N], char *word, int i, int j) {
    if (!is_legal(i, j)) {
        return 0;
    }
    if (*word == '\0') {
        return 1;
    }
    int sum = 0;
    int rows[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int cols[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++) {
        if (letters[i + rows[k]][j + cols[k]] == word[0]) {
            letters[i + rows[k]][j + cols[k]] -= DIFF;
            sum += aux(letters, word + 1, i + rows[k], j + cols[k]);
            letters[i + rows[k]][j + cols[k]] += DIFF;
        }
    }
    return sum;
}

int find_num_of_occurences(char letters[M][N], char *word) {
    if (*word == '\0') {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (letters[i][j] == word[0]) {
                letters[i][j] -= DIFF;
                sum += aux(letters, word + 1, i, j);
                letters[i][j] += DIFF;
            }
        }
    }
    return sum;
}

int main(void) {
    char letters[M][N] = {
            {'D', 'E', 'M', 'X', 'B'},
            {'A', 'O', 'E', 'P', 'E'},
            {'D', 'D', 'C', 'O', 'D'},
            {'E', 'B', 'E', 'D', 'S'},
            {'C', 'P', 'Y', 'E', 'N'},
    };
    int num = find_num_of_occurences(letters, "CODE");
    printf("%d\n", num);
    return 0;
}
