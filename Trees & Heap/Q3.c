/*
Convert a minHeap to maxHeap.
*/
#include <stdio.h>

// Function to maintain the max-heap property at a given index
void maxHeapify(int heap[], int index, int heapSize) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Check if the left child is larger than the current largest
    if (left < heapSize && heap[left] > heap[largest]) {
        largest = left;
    }

    // Check if the right child is larger than the current largest
    if (right < heapSize && heap[right] > heap[largest]) {
        largest = right;
    }

    // If the largest is not the current index, swap the elements and recursively maxHeapify
    if (largest != index) {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        maxHeapify(heap, largest, heapSize);
    }
}

// Function to convert a min-heap into a max-heap
void convertMinToMaxHeap(int heap[], int heapSize) {
    // Start from the last non-leaf node and perform maxHeapify on each
    for (int i = (heapSize - 2) / 2; i >= 0; --i) {
        maxHeapify(heap, i, heapSize);
    }
}

// Function to print the elements of the heap
void printHeap(int heap[], int heapSize) {
    for (int i = 0; i < heapSize; ++i) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int minHeap[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int heapSize = sizeof(minHeap) / sizeof(minHeap[0]);

    printf("Min-Heap: ");
    printHeap(minHeap, heapSize);

    // Convert the given min-heap into a max-heap
    convertMinToMaxHeap(minHeap, heapSize);

    printf("Max-Heap after conversion: ");
    printHeap(minHeap, heapSize);

    return 0;
}
