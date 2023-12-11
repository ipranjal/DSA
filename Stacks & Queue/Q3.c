/*
Implement stack using doubly linked list and show all the operations
of stack.

Author - Pranjal Pandey
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// pointer to the first node of linked list
struct node *start = NULL;

/**
 * Function to push
 */
void push(int element)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = NULL;
    new_node->prev = NULL;

    // Check if list is empty and this is first node
    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}

/**
 * Function to pop
 */
int pop()
{
    struct node *ptr;
    ptr = start;
    int element;

    if (start == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        element = ptr->data;

        if (ptr->prev != NULL)
        {
            //delink the pointer before removing element
            ptr->prev->next = NULL;
        }
        else
        {
            // If its the only elmemnt in stack
            start = NULL;
        }
        free(ptr);
        return element;
    }
}

/**
 * Function to display
 */
void display()
{
    struct node *ptr;
    ptr = start;

    if (start == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

/**
 * Main function to run and test program
 */
int main()
{
    int choice, element;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            if (element != -1)
            {
                printf("Popped element: %d\n", element);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}