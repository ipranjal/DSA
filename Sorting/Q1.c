/*
1. The pivot used in Quicksort may have a significant impact on its performance. Some
popular options include:
A. The first component is
B. The middle component
C. A component is chosen at random
D. The array's median element
E. The median member of the array's first three elements
Write a code that considers an example for quicksort and Comment on each of the
above options by implementing it and analyzing it. What are the advantages and
disadvantages of each? In what circumstances are they excellent or terrible ideas?

Author: Pranjal Pandey
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in the array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high, char pivot_option)
{
    // Declare variables for pivot selection
    int pivot_index, first, middle, last, j, k;
    int first_three[3];

    // Select the pivot element based on the chosen option
    switch (pivot_option)
    {
    case 'A':
        pivot_index = low; // Pivot is the first element
        break;
    case 'B':
        pivot_index = (low + high) / 2; // Pivot is the middle element
        break;
    case 'C':
        pivot_index = low + rand() % (high - low + 1); // Pivot is a random element
        break;
    case 'D':
        // Find the median of the first, middle, and last elements
        first = arr[low];
        middle = arr[(low + high) / 2];
        last = arr[high];
        if ((first <= middle && middle <= last) || (last <= middle && middle <= first))
        {
            pivot_index = (low + high) / 2;
        }
        else if ((middle <= first && first <= last) || (last <= first && first <= middle))
        {
            pivot_index = low;
        }
        else
        {
            pivot_index = high;
        }
        break;
    case 'E':
        // Find the median of the first three elements
        first_three[0] = arr[low];
        first_three[1] = arr[low + 1];
        first_three[2] = arr[low + 2];
        for (j = 0; j < 2; j++)
        {
            for (k = j + 1; k < 3; k++)
            {
                if (first_three[j] > first_three[k])
                {
                    swap(&first_three[j], &first_three[k]);
                }
            }
        }
        if (first_three[1] == arr[low])
        {
            pivot_index = low;
        }
        else if (first_three[1] == arr[low + 1])
        {
            pivot_index = low + 1;
        }
        else
        {
            pivot_index = low + 2;
        }
        break;
    }

    // Swap the pivot element with the last element
    swap(&arr[pivot_index], &arr[high]);

    // Partition the array
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < arr[high])
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    // Return the index of the pivot element
    return i + 1;
}

// Quicksort function
void quicksort(int arr[], int low, int high, char pivot_option)
{
    if (low < high)
    {
        // Partition the array
        int pivot_index = partition(arr, low, high, pivot_option);

        // Recursively sort the left and right subarrays
        quicksort(arr, low, pivot_index - 1, pivot_option);
        quicksort(arr, pivot_index + 1, high, pivot_option);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    char pivot_option;
    printf("Select pivot option (A, B, C, D, or E): ");
    scanf(" %c", &pivot_option);

    // Set the seed for the random number generator
    srand(time(NULL));

    // Sort the array using quicksort
    quicksort(arr, 0, n - 1, pivot_option);

    printf("Sorted array using pivot option %c: ", pivot_option);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print explanations of pivot selection options
    printf("Pivot Selection Options in Quicksort:\n");

    // Option A: The first component as the pivot
    printf("A. The first component as the pivot:\n");
    printf("   - Advantages:\n");
    printf("     - Simple to implement.\n");
    printf("     - Works well for many types of data distributions.\n");
    printf("   - Disadvantages:\n");
    printf("     - Vulnerable to poor performance on already sorted or nearly sorted data.\n");
    printf("   - Circumstances:\n");
    printf("     - A good default choice for general-purpose Quicksort implementations when you don't have specific information about the data distribution.\n");
    printf("\n");

    // Option B: The middle component as the pivot
    printf("B. The middle component as the pivot:\n");
    printf("   - Advantages:\n");
    printf("     - Simple to implement.\n");
    printf("     - Works well for many types of data distributions.\n");
    printf("   - Disadvantages:\n");
    printf("     - Vulnerable to poor performance on already sorted or nearly sorted data.\n");
    printf("   - Circumstances:\n");
    printf("     - A good default choice for general-purpose Quicksort implementations when you don't have specific information about the data distribution.\n");
    printf("\n");

    // Option C: A component chosen at random as the pivot
    printf("C. A component chosen at random as the pivot:\n");
    printf("   - Advantages:\n");
    printf("     - Works well for many types of data distributions.\n");
    printf("     - Avoids the worst-case performance of option A.\n");
    printf("   - Disadvantages:\n");
    printf("     - Requires a random number generator.\n");
    printf("     - Can be slow in practice.\n");
    printf("   - Circumstances:\n");
    printf("     - A good default choice for general-purpose Quicksort implementations when you don't have specific information about the data distribution.\n");
    printf("\n");

    // Option D: The array's median element as the pivot
    printf("D. The array's median element as the pivot:\n");
    printf("   - Advantages:\n");
    printf("     - Avoids the worst-case performance of option A.\n");
    printf("     - Works well for many types of data distributions.\n");
    printf("   - Disadvantages:\n");
    printf("     - Requires finding the median of the array.\n");
    printf("     - Can be slow in practice.\n");
    printf("   - Circumstances:\n");
    printf("     - Useful when you have specific information about the data distribution.\n");

    // Option E: The median member of the array's first three elements as the pivot
    printf("E. The median member of the array's first three elements as the pivot:\n");
    printf("   - Advantages:\n");
    printf("     - Avoids the worst-case performance of option A.\n");
    printf("     - Works well for many types of data distributions.\n");
    printf("   - Disadvantages:\n");
    printf("     - Requires finding the median of the first three elements.\n");
    printf("     - Can be slow in practice.\n");
    printf("   - Circumstances:\n");
    printf("     - Useful when you have specific information about the data distribution.\n");

    return 0;
}
