/*
WAP to implement a special kind of stack that
supports finding minimum element in the stack along with the basic
operations of the stack. Note that all the stack operations must take
O(1) time and space complexity.

Author - Pranjal Pandey
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 


// implement stack
struct stack
{
    int top;
    int capacity;
    int *array;
    int min_top;
    int *min_array;
};

struct stack *s = NULL;

/**
 * Function to create a stack of given capacity.
 * It initializes size of stack as 0
 */
struct stack *create_stack(int capacity)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->capacity = capacity;
    s->top = -1;
    s->min_top = -1;
    s->array = (int *)malloc(s->capacity * sizeof(int));
    s->min_array = (int *)malloc(s->capacity * sizeof(int));
    return s;
}

/**
 * Function to push an element to the stack
 */
void push(int element)
{
    if (s->top == s->capacity - 1)
    {
        printf("Stack Full\n");
    }
    else
    {
        if(s->min_top == -1){
            s->min_array[++s->min_top] = element;
        }
        else if(element < s->min_array[s->min_top]){
             s->min_array[++s->min_top] = element;
        }
        s->array[++s->top] = element;

    }
}

/**
 * Function to pop an element from the stack
 */
int pop()
{
    int element;
    if (s->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    else
    {
        element = s->array[s->top--];
        if(element == s->min_array[s->min_top]){
            s->min_top--;
        }
        return element;
    }
}

/**
 * Function to get the minimum element from the stack
 */
int get_min()
{
    if (s->min_top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    else
    {
        return s->min_array[s->min_top];
    }
}

/**
 * Main function to run and test program
 */
int main(){
    int capacity, choice, element, min;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);
    s = create_stack(capacity);
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Get Minimum\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            if (element != -1)
            {
                printf("Popped element is %d\n", element);
            }
            break;
        case 3:
            min = get_min();
            if (min != -1)
            {
                printf("Minimum element is %d\n", min);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}