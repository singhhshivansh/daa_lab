/* Floyd-Warshall Algorithm - All Pairs Shortest Path (Dynamic Programming) */
#include <stdio.h>

#define V 4
#define INF 99999

void show(int m[V][V]) {
    for (int i = 0; i < V; i++) {
        printf("  ");
        for (int j = 0; j < V; j++) {
            if (m[i][j] == INF) printf("%5s", "INF");
            else                printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int g[V][V] = {{0,   3,   INF, 7},
                   {8,   0,   2,   INF},
                   {5,   INF, 0,   1},
                   {2,   INF, INF, 0}};
    int d[V][V], nxt[V][V];

    printf("Input graph (adjacency matrix):\n");
    show(g);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            d[i][j] = g[i][j];
            nxt[i][j] = (g[i][j] != INF && i != j) ? j : -1;
        }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }

    printf("\nAll-pairs shortest distances:\n");
    show(d);

    printf("\nSample shortest paths:\n");
    int pairs[3][2] = {{0, 3}, {1, 0}, {3, 2}};
    for (int p = 0; p < 3; p++) {
        int u = pairs[p][0], v = pairs[p][1];
        printf("  %d -> %d: %d", u, v, u);
        while (u != v) { u = nxt[u][v]; printf(" -> %d", u); }
        printf("  (cost %d)\n", d[pairs[p][0]][v]);
    }
    return 0;
}
