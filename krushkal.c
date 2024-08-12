#include <stdio.h>

#define INF 999   // A large value representing infinity
#define MAX 100   // Maximum number of vertices

int p[MAX], c[MAX][MAX], t[MAX][2];  // Arrays to hold parent information, cost matrix, and spanning tree

// Function to find the root or representative of a set
int find(int v) {
    while (p[v]) {
        v = p[v];
    }
    return v;
}

// Function to perform union of two sets
void union1(int i, int j) {
    p[j] = i;
}

// Function to implement Kruskal's algorithm
void kruskal(int n) {
    int i, j, k, u, v, min, res1, res2, sum = 0;
    
    // Repeat for n-1 edges
    for (k = 1; k < n; k++) {
        min = INF;
        
        // Find the edge with the smallest weight that does not form a cycle
        for (i = 1; i < n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j) continue;  // Skip self-loops
                
                if (c[i][j] < min) {
                    u = find(i);
                    v = find(j);
                    
                    if (u != v) {
                        res1 = i;
                        res2 = j;
                        min = c[i][j];
                    }
                }
            }
        }
        
        // Perform union and add the edge to the spanning tree
        union1(res1, find(res2));
        t[k][0] = res1;
        t[k][1] = res2;
        sum += min;
    }
    
    // Output the results
    printf("\nCost of spanning tree is=%d\n", sum);
    printf("Edges of spanning tree are:\n");
    for (i = 1; i < n; i++) {
        printf("%d -> %d\n", t[i][0], t[i][1]);
    }
}

int main() {
    int i, j, n;
    
    // Input number of vertices
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    
    // Initialize parent array
    for (i = 1; i <= n; i++) {
        p[i] = 0;
    }
    
    // Input the adjacency matrix
    printf("\nEnter the graph data (adjacency matrix):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            
            // Set non-edges to infinity
            if (c[i][j] == 0 && i != j) {
                c[i][j] = INF;
            }
        }
    }
    
    // Call Kruskal's algorithm
    kruskal(n);
    
    return 0;
}
