/**
 Determine the length of the longest subsequence within an array of integers. This
subsequence must consist of consecutive integers, and the order of these integers can be
flexible. The goal is to find the maximum length of such a subsequence while ensuring that all
distinct values are included.

Example:
Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int longestSubsequence(int *arr, int size)
{
    int *hash = (int *)calloc(1000, sizeof(int));
    int max = 0;
    int length =0; 

    for (int i = 0; i < size; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 0; i < size; i++)
    {
        // if the element is the first element of the subsequence
        if (hash[arr[i] - 1] == 0)
        {
            int j = arr[i];
            while (hash[j] != 0)
            {
                j++;
                length++;
            }
            if (max < length)
            {
                max = length;
                length = 0;
            }
        }
    }
    return max;
}

int main()
{
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Longest subsequence length: %d\n", longestSubsequence(arr, size));
    return 0;
}