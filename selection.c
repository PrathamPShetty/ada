#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void selsort(int a[], int n) {
    int i, j, small, pos, temp;
    
    for (j = 0; j < n - 1; j++) {
        small = a[j];  
        pos = j;      
        
   
        for (i = j + 1; i < n; i++) {
            if (a[i] < small) {
                small = a[i];

                pos = i;
         
            }
        }  
        // printf(" \n small > %d   ", small);
        //  printf("a[j] > %d \n",a[j] );
          
        temp = a[j];
        a[j] = small;
        a[pos] = temp;

        // for (i = 0; i < n; i++)
        //      printf("%d  ", a[i]);
    }
}

int main() {
    int a[500], i, n;
    srand(time(NULL)); 
    clock_t start, end;
    float dura;         


    printf("\nEnter the n value: ");
    scanf("%d", &n);


    printf("\nEnter the array:\n");
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;


    printf("\nThe array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);

    start = clock();
    selsort(a, n);
    end = clock();

    dura = (float)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    printf("\nTime taken is: %f seconds\n", dura);

    return 0;
}
