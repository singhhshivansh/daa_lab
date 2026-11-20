/* Bellman-Ford Algorithm - Single Source Shortest Path (negative edges allowed) */
#include <stdio.h>

#define INF 9999

typedef struct { int u, v, w; } Edge;

/* returns 0 if a negative weight cycle is reachable from src */
int bellman_ford(int V, int E, Edge e[], int src, int dist[]) {
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int pass = 1; pass < V; pass++) {
        for (int j = 0; j < E; j++)
            if (dist[e[j].u] != INF && dist[e[j].u] + e[j].w < dist[e[j].v])
                dist[e[j].v] = dist[e[j].u] + e[j].w;
        printf("After pass %d:", pass);
        for (int i = 0; i < V; i++) printf(" %c=%d", 'A' + i, dist[i]);
        printf("\n");
    }
    for (int j = 0; j < E; j++)                 /* negative cycle check */
        if (dist[e[j].u] != INF && dist[e[j].u] + e[j].w < dist[e[j].v])
            return 0;
    return 1;
}

int main(void) {
    Edge e[] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
                {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    int dist[5];

    if (bellman_ford(5, 8, e, 0, dist)) {
        printf("\nShortest distances from A:\n");
        for (int i = 0; i < 5; i++) printf("  A -> %c = %d\n", 'A' + i, dist[i]);
    } else
        printf("Graph contains a negative weight cycle\n");

    printf("\nTesting graph with a negative cycle:\n");
    Edge bad[] = {{0, 1, 1}, {1, 2, -3}, {2, 0, 1}};
    int d2[3];
    printf("Result: %s\n", bellman_ford(3, 3, bad, 0, d2)
                           ? "No negative cycle" : "Negative cycle detected!");
    return 0;
}
