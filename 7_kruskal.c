#include <stdio.h>

int parent[20];

int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

int main() {
    int n, e, i, j, t, count = 0, total = 0, a, b;
    int eu[50], ev[50], ew[50];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter each edge as: vertex1 vertex2 weight\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &eu[i], &ev[i], &ew[i]);
    }

    for (i = 0; i < e; i++) {
        for (j = i + 1; j < e; j++) {
            if (ew[j] < ew[i]) {
                t = ew[i]; ew[i] = ew[j]; ew[j] = t;
                t = eu[i]; eu[i] = eu[j]; eu[j] = t;
                t = ev[i]; ev[i] = ev[j]; ev[j] = t;
            }
        }
    }

    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("MST edges:\n");
    for (i = 0; i < e && count < n - 1; i++) {
        a = find(eu[i]);
        b = find(ev[i]);
        if (a != b) {
            parent[a] = b;
            printf("%d - %d (weight %d)\n", eu[i], ev[i], ew[i]);
            total = total + ew[i];
            count = count + 1;
        }
    }

    if (count < n - 1) {
        printf("Graph is not connected\n");
    }
    printf("Total cost = %d\n", total);
    return 0;
}
