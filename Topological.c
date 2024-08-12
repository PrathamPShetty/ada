#include <stdio.h>

#define MAX 10

int temp[MAX], k = 0;

void sort(int a[MAX][MAX], int id[], int n) {
    int i, j;
    
   
    for (i = 1; i <= n; i++) {
        if (id[i] == 0) {  
            id[i] = -1;  
            temp[++k] = i;  
            
            for (j = 1; j <= n; j++) {
                if (a[i][j] == 1 && id[j] != -1) {
                    id[j]--;  
                }
            }
            i = 0;  
        }
    }
}

int main() {
    int a[MAX][MAX], id[MAX], n, i, j;
    
    printf("\nEnter the number of vertices (n): ");
    scanf("%d", &n);
    
   
    for (i = 1; i <= n; i++) {
        id[i] = 0;
    }
    

    printf("\nEnter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) {
                id[j]++;  
            }
        }
    }
    

    sort(a, id, n);
    

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
