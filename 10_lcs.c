/* Longest Common Subsequence - Dynamic Programming */
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *X = "AGGTAB", *Y = "GXTXAYB";
    int m = strlen(X), n = strlen(Y);
    int L[20][20];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = L[i - 1][j] > L[i][j - 1] ? L[i - 1][j] : L[i][j - 1];
        }

    printf("X = %s\nY = %s\n\nLCS table:\n", X, Y);
    printf("      -");
    for (int j = 0; j < n; j++) printf("  %c", Y[j]);
    printf("\n");
    for (int i = 0; i <= m; i++) {
        printf("  %c ", i == 0 ? '-' : X[i - 1]);
        for (int j = 0; j <= n; j++) printf("%3d", L[i][j]);
        printf("\n");
    }

    int len = L[m][n];
    char lcs[20];
    lcs[len] = '\0';
    int i = m, j = n, k = len - 1;
    while (i > 0 && j > 0) {                    /* trace back */
        if (X[i - 1] == Y[j - 1]) { lcs[k--] = X[i - 1]; i--; j--; }
        else if (L[i - 1][j] >= L[i][j - 1]) i--;
        else j--;
    }
    printf("\nLength of LCS = %d\n", len);
    printf("LCS           = %s\n", lcs);
    return 0;
}
