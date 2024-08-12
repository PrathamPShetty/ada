#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to perform selection sort on an array
void selsort(int a[], int n) {
    int i, j, small, pos, temp;
    
    for (j = 0; j < n - 1; j++) {
        small = a[j];  // Assume the first element is the smallest
        pos = j;       // Position of the assumed smallest element
        
        // Find the actual smallest element in the remaining unsorted part
        for (i = j + 1; i < n; i++) {
            if (a[i] < small) {
                small = a[i];

                pos = i;
         
            }
        }  
        // printf(" \n small > %d   ", small);
        //  printf("a[j] > %d \n",a[j] );
          
        // Swap the found smallest element with the first unsorted element
        temp = a[j];
        a[j] = small;
        a[pos] = temp;

        // for (i = 0; i < n; i++)
        //      printf("%d  ", a[i]);
    }
}

int main() {
    int a[500], i, n;
    srand(time(NULL));  // Seed the random number generator with current time
    clock_t start, end; // Variables to store start and end times for duration measurement
    float dura;         // Variable to store the duration

    // Input the number of elements in the array
    printf("\nEnter the n value: ");
    scanf("%d", &n);

    // Generate random values for the array
    printf("\nEnter the array:\n");
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;

    // Display the array before sorting
    printf("\nThe array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);

    // Measure the time taken for sorting
    start = clock();
    selsort(a, n);
    end = clock();
    
    // Calculate the duration in seconds
    dura = (float)(end - start) / CLOCKS_PER_SEC;

    // Display the sorted array
    printf("\nSorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    // Display the time taken for sorting
    printf("\nTime taken is: %f seconds\n", dura);

    return 0;
}
