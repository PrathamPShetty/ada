#include <stdio.h>
#define INF 999  // Define infinity as 999 for representation

// Function to find the minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to perform the Floyd-Warshall algorithm
void floyd(int p[][10], int n) {
    int i, j, k;
    
    // Iterating through each possible intermediate vertex
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Update the shortest path for the pair (i, j) using vertex k as an intermediate point
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
}

// Main function to drive the program
int main() {
    int a[10][10], n, i, j;
    
    // Input number of vertices
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);
    
    // Input the adjacency matrix
    printf("Enter the adjacency matrix (enter %d for infinity):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    // Call the Floyd-Warshall function
    floyd(a, n);
    
    // Output the shortest path matrix
    printf("Shortest path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == INF) {
                printf("%4s", "INF");  // Print "INF" for infinite distances
            } else {
                printf("%4d", a[i][j]);  // Print the shortest distance
            }
        }
        printf("\n");
    }
    
    return 0;
}
