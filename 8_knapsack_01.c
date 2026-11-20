/* 0/1 Knapsack Problem - Dynamic Programming */
#include <stdio.h>

#define N 4
#define W 50

int max(int a, int b) { return a > b ? a : b; }

int main(void) {
    int val[N] = {60, 100, 120, 70};
    int wt[N]  = {10, 20, 30, 15};
    int dp[N + 1][W + 1];

    for (int i = 0; i <= N; i++)
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }

    printf("Values : 60 100 120 70\n");
    printf("Weights: 10 20 30 15\n");
    printf("Capacity: %d\n", W);
    printf("\nDP table (columns = capacity 0,10,20,30,40,50):\n");
    for (int i = 0; i <= N; i++) {
        printf("  item %d:", i);
        for (int w = 0; w <= W; w += 10) printf("%5d", dp[i][w]);
        printf("\n");
    }
    printf("\nMaximum value = %d\n", dp[N][W]);

    int chosen[N], cnt = 0, w = W;               /* backtrack through the table */
    for (int i = N; i > 0; i--)
        if (dp[i][w] != dp[i - 1][w]) {
            chosen[cnt++] = i;
            w -= wt[i - 1];
        }
    printf("Items chosen (1-indexed):");
    for (int i = cnt - 1; i >= 0; i--) printf(" %d", chosen[i]);
    printf("\n");
    return 0;
}
