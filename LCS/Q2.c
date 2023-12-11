/*
WAP to implement longest_common_subsequence that calculate the length of the longest
common subsequence between the given �n� strings.
For example:
Input:
Str1: abcdef
Str2: abc
Str3: cdef
Output: The length of LCS is 1, and the string is c.

Author - Pranjal Pandey
*/
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    // Build L[m+1][n+1] in bottom up fashion
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            // If either string is empty, LCS is 0
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                // If last characters are same, add 1 to the result and reduce the problem to the remaining strings
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                // If last characters are different, reduce the problem to the remaining strings
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // L[m][n] contains the length of LCS of X[0..m-1] and Y[0..n-1]
    return L[m][n];
}

int main() {
    int num;
    printf("Enter the number of strings: ");
    scanf("%d", &num);

    char strings[num][100]; // Assuming a maximum string length of 100 characters

    // Input the strings
    int s;
    for (s = 0; s < num; s++) {
        printf("Enter String %d: ", s + 1);
        scanf("%s", strings[s]);
    }

    // Calculate LCS
    int length = lcs(strings[0], strings[1], strlen(strings[0]), strlen(strings[1]));

    for (s = 2; s < num; s++) {
        length = lcs(strings[s], strings[0], strlen(strings[s]), length);
    }

    printf("The length of LCS is %d\n", length);
    
    // Reconstruct the LCS
    char lcsString[length + 1];
    int i = strlen(strings[0]);
    int j = strlen(strings[1]);
    int index = length;

    while (i > 0 && j > 0) {
        if (strings[0][i - 1] == strings[1][j - 1]) {
            lcsString[index - 1] = strings[0][i - 1];
            i--;
            j--;
            index--;
        } else if (lcs(strings[0], strings[1], i - 1, j) > lcs(strings[0], strings[1], i, j - 1)) {
            i--;
        } else {
            j--;
        }
    }

    lcsString[length] = '\0';

    printf("%s\n", lcsString);

    return 0;
}
