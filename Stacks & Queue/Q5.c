/*
WAP to implement a queue using stacks and show all the basic
operations.

Author - Pranjal Pandey
*/

#include <stdio.h>
#include <stdlib.h>

// implement queue using two stacks
struct stack
{
    int top;
    int capacity;
    int *array;
};

struct stack *s1 = NULL;
struct stack *s2 = NULL;

/**
 * Function to push
 */
void push(struct stack *s, int element){
    if (s->top == s->capacity - 1)
    {
        printf("Stack Full\n");
    }
    else
    {
        s->array[++s->top] = element;
    }
}

/**
 * Function to pop
 */
int pop(struct stack *s){
    if (s->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    else
    {
        return s->array[s->top--];
    }
}

/**
 * Function to enqueue
 */
void enqueue(int element){
    push(s1, element);
}

/**
 * Function to dequeue
 */
int dequeue(){
    int element;
    if (s1->top == -1 && s2->top == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (s2->top == -1)
    {
        while (s1->top != -1)
        {
            element = pop(s1);
            push(s2, element);
        }
        return pop(s2);
    }
    else
    {
        // Element already available in top of s2
        return pop(s2);
    }
}



/**
 * Function to create a stack of given capacity.
 * It initializes size of stack as 0
 */
struct stack *create_stack(int capacity){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = (int *)malloc(s->capacity * sizeof(int));
    return s;
}

/**
 * Main function to run and test program
 */
int main()
{
    int choice, element;
    s1 = create_stack(10);
    s2 = create_stack(10);
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            element = dequeue();
            if (element != -1)
            {
                printf("Dequeued element is: %d\n", element);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}