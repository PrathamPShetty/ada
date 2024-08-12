#include <stdio.h>

#define MAX 50

int p[MAX], w[MAX];  // Arrays to store profits and weights
double x[MAX];       // Solution vector
double maxprofit;    // To store the maximum profit
int n, m;            // Number of objects and maximum capacity

// Function to perform the greedy knapsack algorithm
void greedyKnapsack(int n, int w[], int p[], int m) {
    double ratio[MAX];
    
    // Calculate profit-to-weight ratio for each object
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)p[i] / w[i];
    }

    // Sort objects based on their profit-to-weight ratio in decreasing order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                double tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;
                
                int tempWeight = w[i];
                w[i] = w[j];
                w[j] = tempWeight;
                
                int tempProfit = p[i];
                p[i] = p[j];
                p[j] = tempProfit;
            }
        }
    }

    int currentWeight = 0;
    maxprofit = 0.0;
    
    // Iterate through objects and add them to the knapsack
    for (int i = 0; i < n; i++) {
        if (currentWeight + w[i] <= m) {
            x[i] = 1;
            currentWeight += w[i];
            maxprofit += p[i];
        } else {
            x[i] = (double)(m - currentWeight) / w[i];
            maxprofit += x[i] * p[i];
            break;
        }
    }

    // Print the results
    printf("Optimal solution for greedy method: %.1f\n", maxprofit);
    printf("Solution vector for greedy method: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
    }
    printf("\n");
}

// Main function
int main() {
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    
    printf("Enter the objects' weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    printf("Enter the objects' profits: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("Enter the maximum capacity: ");
    scanf("%d", &m);
    
    greedyKnapsack(n, w, p, m);
    
    return 0;
}
