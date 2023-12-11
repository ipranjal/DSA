/*
WAP to merge and sort 'k' sorted arrays efficiently using a min-heap.
*/
#include <stdio.h>
#include <stdlib.h>

// Custom structure for heap elements
struct HeapNode {
    int value;    // Value of the element
    int arrayIdx; // Index of the array containing the element
};

// Custom comparator for min-heap
int compare(const void* a, const void* b) {
    return ((struct HeapNode*)a)->value - ((struct HeapNode*)b)->value;
}

// Function to merge and sort 'k' sorted arrays using a min-heap
int* mergeKSortedArrays(int** arrays, int k, int* sizes, int* mergedSize) {
   
    // Create a min-heap with 'k' heap nodes
    struct HeapNode* heap = (struct HeapNode*)malloc(k * sizeof(struct HeapNode));
    for (int i = 0; i < k; ++i) {
        heap[i].value = arrays[i][0];
        heap[i].arrayIdx = i;
    }

    // Convert the heap into a min-heap
    qsort(heap, k, sizeof(struct HeapNode), compare);

    // Create an array to store the merged array
    int* mergedArray = (int*)malloc((*mergedSize) * sizeof(int));

    // Merge the arrays until the heap becomes empty
    int i = 0;
    while (k > 0) {
        // Store the root of the heap in the merged array
        mergedArray[i++] = heap[0].value;

        // If the array containing the root has more elements, replace the root with the next element
        if (sizes[heap[0].arrayIdx] > 1) {
            heap[0].value = arrays[heap[0].arrayIdx][1];
            arrays[heap[0].arrayIdx]++;
            sizes[heap[0].arrayIdx]--;
        } else {
            // If the array containing the root has no more elements, replace the root with the last element
            heap[0].value = heap[k - 1].value;
            heap[0].arrayIdx = heap[k - 1].arrayIdx;
            k--;
        }

        // Maintain the min-heap property
        qsort(heap, k, sizeof(struct HeapNode), compare);
    }

    // Free allocated memory
    free(heap);

    return mergedArray;

}

int main() {
    int k = 3;
    int sizes[] = {4, 5, 6};
    int* arrays[] = {
        (int[]){1, 3, 5, 7},
        (int[]){2, 4, 6, 8, 10},
        (int[]){0, 9, 11, 12, 13, 14}
    };
    int mergedSize = 0;

    for (int i = 0; i < k; ++i) {
        printf("Array %d: ", i + 1);
        for (int j = 0; j < sizes[i]; ++j) {
            printf("%d ", arrays[i][j]);
        }
        printf("\n");
    }

    // Find the size of the merged array
    for (int i = 0; i < k; ++i) {
        mergedSize += sizes[i];
    }

    // Merge and sort the arrays
    int* mergedArray = mergeKSortedArrays(arrays, k, sizes, &mergedSize);

    // Print the merged array
    printf("Merged array: ");
    for (int i = 0; i < mergedSize; ++i) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    // Free allocated memory
    free(mergedArray);

    return 0;
}
