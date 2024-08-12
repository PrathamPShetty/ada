#include <stdio.h>
#define MAX 10

int n;                  // Number of elements in the set
int S[MAX];             // The set of elements
int soln[MAX];          // Solution array to track which elements are included in the subset
int d;                  // The desired sum (subset sum)

void SumofSub(int i, int weight, int total);

void SumofSub(int i, int weight, int total) {
    if ((weight + total >= d) && (weight <= d)) {
        // Check if the current subset's weight equals the desired sum
        if (weight == d) {
            printf("Subset found: ");
            for (int j = 1; j <= i; j++) {
                if (soln[j] == 1)
                    printf("%d ", S[j]);
            }
            printf("\n");
        }
        else {
            // Include the next element in the subset
            soln[i + 1] = 1;
            SumofSub(i + 1, weight + S[i + 1], total - S[i + 1]);
            
            // Exclude the next element from the subset
            soln[i + 1] = 0;
            SumofSub(i + 1, weight, total - S[i + 1]);
        }
    }
}

int main() {
    int sum = 0;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the set in increasing order: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    
    printf("Enter the desired subset sum (d): ");
    scanf("%d", &d);
    
    // Calculate the sum of all elements in the set
    for (int i = 1; i <= n; i++)
        sum += S[i];
    
    // Check if a subset is possible
    if (sum < d || S[1] > d)
        printf("No Subset possible\n");
    else
        SumofSub(0, 0, sum);  // Start the backtracking process
    
    return 0;
}
