#include <stdio.h>
#define MAX 10

int w[MAX], p[MAX], n;

// Function to find the maximum of two values
int max(int a, int b) {
    return a > b ? a : b;
}

// Recursive function to solve the knapsack problem
int knap(int i, int m) {
    if (i == n) {
        return w[i] > m ? 0 : p[i];
    }
    if (w[i] > m) {
        return knap(i + 1, m);
    }
    return max(knap(i + 1, m), knap(i + 1, m - w[i]) + p[i]);
}

// Main function
int main() {
    int m, i, max_profit;

    // Input number of objects
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    // Input knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &m);

    // Input profit and weight for each object
    printf("Enter profit followed by weight for each object:\n");
    for (i = 1; i <= n; i++) {
        printf("Object %d: ", i);
        scanf("%d %d", &p[i], &w[i]);
    }

    // Calculate the maximum profit
    max_profit = knap(1, m);

    // Output the result
    printf("Max profit = %d\n", max_profit);

    return 0;
}
