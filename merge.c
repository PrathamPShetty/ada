#include <stdio.h>
#include <stdlib.h>
#include <time.h>   


// Function to merge two subarrays
void merge(int arr[], int l, int m, int r) {                          
                                                                         
    int i, j, k;
    int n1 = m - l + 1;  // Length of the left subarray
    int n2 = r - m;      // Length of the right subarray

   int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[]
    i = 0;  // Initial index of the first subarray
    j = 0;  // Initial index of the second subarray
    k = l;  // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

  
}

// Function to perform merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // Find the middle point
        mergeSort(arr, l, m);     // Sort the first half
        mergeSort(arr, m + 1, r); // Sort the second half
        merge(arr, l, m, r);      // Merge the sorted halves
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
         arr[i] = rand() % 100;
    }
        for (int i = 0; i < n; i++){

              printf("%d   ",arr[i]);
        }
    // Measure time taken by MergeSort
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array and time taken
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("Time taken by MergeSort: %f seconds\n", cpu_time_used);

    return 0;
}
