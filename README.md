# Data Structure and algorithm
This repository contains a set of questions and solution for some popular data structures

## Linked List

1. Write a program to insert a node at:
a. End of singly linked list
b. Start of singly linked list
c. Middle of a singly linked list.
2. Write a program to remove the nth node from a Linked List.
3. Write a program to reverse a Linked List from position X to position Y.
4. Write a program to merge two sorted Linked lists, L and K.
5. Write a program to remove duplicate elements from an unsorted Linked List.
6. Write a program to create a doubly linked list with functions (inset at
beginning, insert at end, delete from beginning, and delete from end) and
display it in reverse order.
7. Write a program to find the maximum value in a doubly linked list.
8. Write a program to create a circular linked list and insert a node at any
position in the list.
9. Write a program in C to delete a node from the middle of a circular linked
list.
10. Write a program in C to delete a node from any position in a doubly
linked list.

## Stack and Queue

1. WAP to implement stack using a single queue and show all the basic
operations.
2. WAP to implement an expression using stack. For example:
a. Input: str = “1 3 3 * + 9 -“
b. Output: 1
c. Explanation: If the expression is converted into an infix
expression, it will be 1 + (3 * 3) – 9 = 10 – 9 = 1
3. Implement stack using doubly linked list and show all the operations
of stack.
4. Implement a queue using a circular linked list and show all the
operations of the queue.
5. WAP to implement a queue using stacks and show all the basic
operations.

## Hashing 

1. WAP to implement Hashing with double hashing as a collision resolution strategy. Your
program should include – Insert, lookup, and delete operations.
2. WAP to implement Hashing with chaining as a collision resolution strategy. Your program
should include – Insert, lookup, and delete operations.
3. Determine the length of the longest subsequence within an array of integers. This
subsequence must consist of consecutive integers, and the order of these integers can be
flexible. The goal is to find the maximum length of such a subsequence while ensuring that all
distinct values are included.
Example:
Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements
4. Identify symmetric pairs within an array of pairs. Symmetric pairs consist of two pairs (a, b)
and (c, d) where c equals b and a equals d. For instance, (1, 2) and (2, 1) represent a
symmetric pair. This task involves finding all such symmetric pairs within the given array, with
the assumption that the first elements of all pairs are distinct.
5. WAP to check whether there are any two distinct elements within an array A[] of n numbers
whose sum is equal to a given number x.

## Trees and Heap

1. WAP to implement BST given a binary tree and preserving the
structure of the given binary tree.
2. WAP to find the third largest element in the BST. (BST must be a user
input in inorder traversal).
3. Convert a minHeap to maxHeap.
4. WAP to verify whether a given binary search tree is also an AVL tree.
5. WAP to merge and sort 'k' sorted arrays efficiently using a min-heap.
6. Write a program for AVL tree that has functions for the following operations:
Insert an element (no duplicates are allowed).
Delete an existing element,
Traverse the AVL (in-order, pre-order, and post-order)

## Sorting

1. The pivot used in Quicksort may have a significant impact on its performance. Some
popular options include: (50 points)
A. The first component is
B. The middle component
C. A component is chosen at random
D. The array's median element
E. The median member of the array's first three elements
Write a code that considers an example for quicksort and Comment on each of the
above options by implementing it and analyzing it. What are the advantages and
disadvantages of each? In what circumstances are they excellent or terrible ideas?

2. Assume you already have an example code for heapsort (As per your choice). Now
perform the following operation on it: (20 points)

A. Make use of the current heap code. Create a heap object, then loop over your
array of data to sort and add each item to the heap. Then, one at a time, remove
items from the heap, filling up the array from left to right (since the heap function
we developed is a min-heap).
B. Remove the present heap code and replace it with something comparable that
operates directly on the array we have.

## LCS and Matrix Multiplication

1. WAP to implement matrix_chain_multiplication that calculate the minimum number of
scalar multiplications required to multiply the ‘n’ sequence of matrices optimally as well as gives
the order of operations.
For example:
Input: ABC are three matrices with 5x10, 10x8, 8x5 dimensions.
Output: # minimum scaler operations: 600 and the order of operations: ((AB).C)

2. WAP to implement longest_common_subsequence that calculate the length of the longest
common subsequence between the given ‘n’ strings.
For example:
Input:
Str1: abcdef
Str2: abc
Str3: cdef
Output: The length of LCS is 1, and the string is c.
