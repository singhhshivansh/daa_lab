/* Matrix Chain Multiplication - Dynamic Programming */
#include <stdio.h>
#include <limits.h>

#define N 6
int m[N + 1][N + 1], s[N + 1][N + 1];

void print_parens(int i, int j) {
    if (i == j) { printf("A%d", i); return; }
    printf("(");
    print_parens(i, s[i][j]);
    printf(" x ");
    print_parens(s[i][j] + 1, j);
    printf(")");
}

int main(void) {
    int p[N + 1] = {30, 35, 15, 5, 10, 20, 25};

    for (int len = 2; len <= N; len++)
        for (int i = 1; i <= N - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) { m[i][j] = cost; s[i][j] = k; }
            }
        }

    printf("Dimensions: 30 35 15 5 10 20 25\n");
    for (int i = 1; i <= N; i++)
        printf("  A%d: %d x %d\n", i, p[i - 1], p[i]);

    printf("\nCost table m[i][j]:\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j >= i) printf("%7d", m[i][j]);
            else        printf("%7s", "-");
        }
        printf("\n");
    }
    printf("\nMinimum number of multiplications = %d\n", m[1][N]);
    printf("Optimal parenthesization: ");
    print_parens(1, N);
    printf("\n");
    return 0;
}
