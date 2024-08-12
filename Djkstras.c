#include <stdio.h>
#define INF 999

void dijkstra(int c[10][10], int n, int s, int d[10]) {
    int v[10], min, u, i, j;

    for (i = 0; i < n; i++) {
        d[i] = c[s][i];
        v[i] = 0;
    }

    v[s] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!v[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;

        for (j = 0; j < n; j++) {
            if (!v[j] && (d[u] + c[u][j]) < d[j]) {
                d[j] = d[u] + c[u][j];
            }
        }
    }
}

int main() {
    int c[10][10], d[10], i, j, s, n;

    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter %d for infinity):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter the source node (0 to %d): ", n - 1);
    scanf("%d", &s);

    dijkstra(c, n, s, d);

    printf("Shortest distances from node %d:\n", s);
    for (i = 0; i < n; i++) {
        if (d[i] == INF) {
            printf("To node %d: INF\n", i);
        } else {
            printf("To node %d: %d\n", i, d[i]);
        }
    }

    return 0;
}
