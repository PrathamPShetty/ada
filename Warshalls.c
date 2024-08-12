#include <stdio.h>


void warsh(int p[][10], int n) {
    int i, j, k;
    
  
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j;
    

    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);
    

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    warsh(a, n);
    
 
    printf("Resultant path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
