#include <stdio.h>

int main() {
    int n, i, j, v, count, u, src;
    int cost[20][20], dist[20], visited[20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (0 = no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) {
        dist[i] = 99999;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (count = 0; count < n; count++) {
        u = -1;
        for (i = 0; i < n; i++) {
            if (visited[i] == 0 && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (cost[u][v] != 0 && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("Shortest distance from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == 99999) {
            printf("To %d = not reachable\n", i);
        } else {
            printf("To %d = %d\n", i, dist[i]);
        }
    }
    return 0;
}
