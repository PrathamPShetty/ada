#include <stdio.h>

#define MAX 10

int temp[MAX], k = 0;

void sort(int a[MAX][MAX], int id[], int n) {
    int i, j;
    
    // Continue the process until all vertices are processed
    for (i = 1; i <= n; i++) {
        if (id[i] == 0) {  // If the vertex has no incoming edges
            id[i] = -1;  // Mark the vertex as processed
            temp[++k] = i;  // Add the vertex to the topological order
            
            for (j = 1; j <= n; j++) {
                if (a[i][j] == 1 && id[j] != -1) {
                    id[j]--;  // Reduce the incoming edge count for vertices adjacent to `i`
                }
            }
            i = 0;  // Restart the loop to ensure we pick up all vertices with no incoming edges
        }
    }
}

int main() {
    int a[MAX][MAX], id[MAX], n, i, j;
    
    printf("\nEnter the number of vertices (n): ");
    scanf("%d", &n);
    
    // Initialize in-degree array
    for (i = 1; i <= n; i++) {
        id[i] = 0;
    }
    
    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) {
                id[j]++;  // Increment the in-degree of vertex `j`
            }
        }
    }
    
    // Perform topological sort
    sort(a, id, n);
    
    // Check if topological sorting was successful
    if (k != n) {
        printf("\nTopological ordering not possible\n");
    } else {
        printf("\nTopological ordering is: ");
        for (i = 1; i <= k; i++) {
            printf("%d ", temp[i]);
        }
        printf("\n");
    }
    
    return 0;
}
