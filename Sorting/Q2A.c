/*
A. Heap Sort using a heap object with user input:
Author - Pranjal Pandey
*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a heap
typedef struct {
    int* array;  // Array to store heap elements
    int size;    // Number of elements in the heap
} Heap;

// Function to create a new heap with given size
Heap* createHeap(int size) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));        // Allocate memory for the heap structure
    heap->array = (int*)malloc(size * sizeof(int)); // Allocate memory for the heap array
    heap->size = 0;                                 // Initialize size to 0 (no elements initially)
    return heap;
}

// Function to swap two elements in the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify on a subtree rooted at index 'i'
void heapify(Heap* heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);  // Recursively heapify the affected sub-tree
    }
}

// Function to build a max heap from an array
void buildMaxHeap(Heap* heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--) {
        heapify(heap, i); // Perform heapify on each non-leaf node
    }
}

// Main function to perform Heap Sort
void heapSort(Heap* heap) {
    buildMaxHeap(heap); // Build a max heap from the given array
    for (int i = heap->size - 1; i > 0; i--) {
        swap(&heap->array[0], &heap->array[i]); // Move the current root to the end
        heap->size--;                            // Decrease heap size (effectively removing the largest element)
        heapify(heap, 0);                        // Call heapify on the reduced heap
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Heap* heap = createHeap(n); // Create a new heap with the specified size

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &heap->array[i]); // Read elements from user input
        heap->size++;                 // Increase heap size after adding an element
    }

    heapSort(heap); // Sort the heap using heap sort algorithm

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", heap->array[i]); // Print the sorted elements
    }
    printf("\n");


    return 0;
}
