/*
WAP to check whether there are any two distinct elements within an array A[] of n numbers
whose sum is equal to a given number x.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, i, j, k, flag = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the value of x: ");
    scanf("%d", &x);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            if (arr[i] + arr[j] == x)
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}