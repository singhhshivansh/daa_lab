/* Travelling Salesman Problem - Dynamic Programming (Held-Karp, bitmask) */
#include <stdio.h>

#define N 4
#define INF 99999

int main(void) {
    int d[N][N] = {{0, 10, 15, 20},
                   {10, 0, 35, 25},
                   {15, 35, 0, 30},
                   {20, 25, 30, 0}};
    int dp[1 << N][N], par[1 << N][N];

    for (int m = 0; m < (1 << N); m++)
        for (int i = 0; i < N; i++) { dp[m][i] = INF; par[m][i] = -1; }
    dp[1][0] = 0;                               /* start at city 0 */

    for (int mask = 1; mask < (1 << N); mask++)
        for (int i = 0; i < N; i++) {
            if (!(mask & (1 << i)) || dp[mask][i] == INF) continue;
            for (int j = 0; j < N; j++) {
                if (mask & (1 << j)) continue;
                int nm = mask | (1 << j);
                if (dp[mask][i] + d[i][j] < dp[nm][j]) {
                    dp[nm][j] = dp[mask][i] + d[i][j];
                    par[nm][j] = i;
                }
            }
        }

    int full = (1 << N) - 1, best = INF, last = -1;
    for (int i = 1; i < N; i++)
        if (dp[full][i] + d[i][0] < best) { best = dp[full][i] + d[i][0]; last = i; }

    printf("Distance matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%5d", d[i][j]);
        printf("\n");
    }
    printf("\nMinimum tour cost = %d\n", best);

    int path[N + 1], k = 0, mask = full, cur = last;
    while (cur != -1) {                         /* rebuild the tour backwards */
        path[k++] = cur;
        int p = par[mask][cur];
        mask ^= (1 << cur);
        cur = p;
    }
    printf("Optimal tour      = ");
    for (int i = k - 1; i >= 0; i--) printf("%d -> ", path[i]);
    printf("0");
    printf("\n");
    return 0;
}
