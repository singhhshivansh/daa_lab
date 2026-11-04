#include <stdio.h>

int main() {
    int n, i, j, v, count, u, total = 0;
    int cost[20][20], key[20], visited[20], parent[20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (0 = no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        key[i] = 99999;
        visited[i] = 0;
        parent[i] = -1;
    }
    key[0] = 0;

    printf("MST edges:\n");
    for (count = 0; count < n; count++) {
        u = -1;
        for (i = 0; i < n; i++) {
            if (visited[i] == 0 && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }
        if (key[u] == 99999) {
            printf("Graph is not connected\n");
            return 0;
        }
        visited[u] = 1;

        if (parent[u] != -1) {
            printf("%d - %d (weight %d)\n", parent[u], u, key[u]);
            total = total + key[u];
        }

        for (v = 0; v < n; v++) {
            if (cost[u][v] != 0 && visited[v] == 0 && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Total cost = %d\n", total);
    return 0;
}
