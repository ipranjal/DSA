/*
WAP to implement matrix_chain_multiplication that calculate the minimum number of
scalar multiplications required to multiply the �n� sequence of matrices optimally as well as gives
the order of operations.
For example:
Input: ABC are three matrices with 5x10, 10x8, 8x5 dimensions.
Output: # minimum scaler operations: 600 and the order of operations: ((AB).C)

Author - Pranjal Pandey
*/
#include <stdio.h>
#include <limits.h>

#define MAX_MATRICES 100

// Function to perform matrix chain multiplication
void matrixChainOrder(int p[], int n, int m[MAX_MATRICES][MAX_MATRICES], int s[MAX_MATRICES][MAX_MATRICES]) {
    int i, j, k, l, q;

    // m[i, j] = Minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j] = A[i..j]
    // s[i, j] = Index of the matrix after which the product is split in the minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j] = A[i..j]
    // s[i, j] = k indicates that the product is split between A[k] and A[k+1]
    // m[i, j] = Minimum { m[i, k] + m[k+1, j] + p[i-1]*p[k]*p[j] } where i <= k < j

    // Cost is zero when multiplying one matrix
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // L is chain length
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                // q = Cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Function to print the optimal order of operations
void printOptimalOrder(int s[MAX_MATRICES][MAX_MATRICES], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalOrder(s, i, s[i][j]);
        printOptimalOrder(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int num;
    printf("Enter the number of matrices: ");
    scanf("%d", &num);

    int p[MAX_MATRICES]; // Dimensions of matrices
    printf("Enter the dimensions of the matrices:\n");
    int i;
    for (i = 0; i <= num; i++) {
        scanf("%d", &p[i]);
    }

    int m[MAX_MATRICES][MAX_MATRICES]; // Minimum scalar multiplications
    int s[MAX_MATRICES][MAX_MATRICES]; // Stores the split points

    matrixChainOrder(p, num, m, s);

    printf("Minimum scalar multiplications: %d\n", m[1][num]);
    printf("Order of operations: ");
    printOptimalOrder(s, 1, num);
    printf("\n");

    return 0;
}


