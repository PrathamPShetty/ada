#include <stdio.h>
#include <limits.h>
#define INF 999

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int cost[10][10];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF; 
            }
        }
    }

    int visited[10] = {0};
    visited[0] = 1;
    int mincost = 0; 

    printf("\nEdges in the Minimum Spanning Tree:\n");

    for (int edges = 1; edges < n; edges++) {
        int min = INF; 
        int u = -1, v = -1;


        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }


        if (u != -1 && v != -1) {
            printf("Edge %d: (%d %d) cost: %d\n", edges, u + 1, v + 1, min);
            mincost += min;
            visited[v] = 1; 
        }
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
