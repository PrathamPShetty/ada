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
                cost[i][j] = INF; // Set non-edges to infinity
            }
        }
    }

    int visited[10] = {0}; // Array to track visited nodes
    visited[0] = 1; // Start with the first node
    int mincost = 0; // To store the total cost of the MST

    printf("\nEdges in the Minimum Spanning Tree:\n");

    for (int edges = 1; edges < n; edges++) {
        int min = INF; // Initialize minimum cost to infinity
        int u = -1, v = -1; // To store the nodes of the minimum edge

        // Find the edge with the minimum cost that connects a visited node to an unvisited node
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

        // If a valid edge is found
        if (u != -1 && v != -1) {
            printf("Edge %d: (%d %d) cost: %d\n", edges, u + 1, v + 1, min);
            mincost += min; // Add the cost of this edge to the total cost
            visited[v] = 1; // Mark the new node as visited
        }
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
