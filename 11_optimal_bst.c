/* Optimal Binary Search Tree - Dynamic Programming */
#include <stdio.h>

#define N 4
int keys[N] = {10, 20, 30, 40};
int freq[N] = {4, 2, 6, 3};
int cost[N + 1][N + 1], root[N + 1][N + 1];

void show(int i, int j, int depth, const char *side) {
    if (i > j) return;
    int r = root[i][j];
    for (int d = 0; d < depth; d++) printf("    ");
    printf("%s: %d\n", side, keys[r]);
    show(i, r - 1, depth + 1, "L");
    show(r + 1, j, depth + 1, "R");
}

int main(void) {
    for (int i = 0; i < N; i++) { cost[i][i] = freq[i]; root[i][i] = i; }

    for (int len = 2; len <= N; len++)
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1, sum = 0;
            for (int k = i; k <= j; k++) sum += freq[k];
            cost[i][j] = 1 << 30;
            for (int r = i; r <= j; r++) {
                int left  = (r > i) ? cost[i][r - 1] : 0;
                int right = (r < j) ? cost[r + 1][j] : 0;
                if (left + right + sum < cost[i][j]) {
                    cost[i][j] = left + right + sum;
                    root[i][j] = r;
                }
            }
        }

    printf("Keys        : 10 20 30 40\n");
    printf("Frequencies : 4 2 6 3\n");
    printf("\nCost table:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%5d", cost[i][j]);
        printf("\n");
    }
    printf("\nMinimum search cost = %d\n", cost[0][N - 1]);
    printf("\nStructure of Optimal BST:\n");
    show(0, N - 1, 0, "Root");
    return 0;
}
