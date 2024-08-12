#include <stdio.h>
#define MAX 10

int n;               
int S[MAX];            
int soln[MAX];        
int d;                

void SumofSub(int i, int weight, int total);

void SumofSub(int i, int weight, int total) {
    if ((weight + total >= d) && (weight <= d)) {
        
        if (weight == d) {
            printf("Subset found: ");
            for (int j = 1; j <= i; j++) {
                if (soln[j] == 1)
                    printf("%d ", S[j]);
            }
            printf("\n");
        }
        else {
           
            soln[i + 1] = 1;
            SumofSub(i + 1, weight + S[i + 1], total - S[i + 1]);
            
  
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
    
   
    for (int i = 1; i <= n; i++)
        sum += S[i];
    

    if (sum < d || S[1] > d)
        printf("No Subset possible\n");
    else
        SumofSub(0, 0, sum); 
    
    return 0;
}
