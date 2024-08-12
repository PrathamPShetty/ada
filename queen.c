#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

// Function to check if a queen can be placed at a specific position
int can_place(int c[], int r) {
    int i;
    for (i = 0; i < r; i++) {
        if (c[i] == c[r] || abs(c[i] - c[r]) == abs(i - r)) {
            return 0;
        }
    }
    return 1;
}

// Function to display the chessboard with the queens placed
void display(int c[], int n) {
    int i, j;
    char cb[10][10];

    // Initialize the chessboard with empty spaces
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cb[i][j] = '-';
        }
    }

    // Place the queens on the chessboard
    for (i = 0; i < n; i++) {
        cb[i][c[i]] = 'Q';
    }

    // Print the chessboard
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", cb[i][j]);
        }
        printf("\n");
    }
}

// Function to solve the N-Queens problem
void n_queens(int n) {
    int r;
    int c[MAX];
    c[0] = -1;  // Start with the first queen
    r = 0;

    while (r >= 0) {
        c[r]++;  // Move to the next column

        // Check if the queen can be placed
        while (c[r] < n && !can_place(c, r)) {
            c[r]++;
        }

        if (c[r] < n) {
            if (r == n - 1) {
                // If all queens are placed, display the solution
                display(c, n);
                printf("\n");
            } else {
                // Move to the next row
                r++;
                c[r] = -1;
            }
        } else {
            r--;  // Backtrack to the previous row
        }
    }
}

// Main function
int main() {
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);
    n_queens(n);
    return 0;
}
