#include <stdio.h>

// Function to implement Warshall's algorithm
void warsh(int p[][10], int n) {
    int i, j, k;
    
    // Iterate through each possible intermediate vertex
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Update the reachability matrix using the transitive property
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j;
    
    // Input number of vertices
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);
    
    // Input the adjacency matrix
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    // Call Warshall's algorithm
    warsh(a, n);
    
    // Output the resultant path matrix
    printf("Resultant path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
