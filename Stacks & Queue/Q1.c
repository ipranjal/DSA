/*
WAP to implement stack using a single queue and show all the basic
operations.

Author - Pranjal Pandey
*/

#include <stdio.h>
#include <stdlib.h>

// implement stack using a single queue
struct queue
{
    int data;
    struct queue *next;
};

// pointer to the first node of linked list
struct queue *start = NULL;

/**
 * Function to enqueue
*/
void enqueue(int element)
{
    struct queue *new_node, *ptr;
    new_node = (struct queue *)malloc(sizeof(struct queue));
    new_node->data = element;
    new_node->next = NULL;

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
    }
}

/**
 * Function to dequeue
*/
int dequeue()
{
    struct queue *ptr;
    ptr = start;
    int element;

    if (start == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int element = ptr->data;
        start = ptr->next;
        free(ptr);
        return element;
    }
}

/**
 * Count number of elements in queue
*/
int count_elements()
{
    struct queue *ptr;
    ptr = start;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

/**
 * Implement stack push using queue
*/
void push()
{
    int element;
    printf("Enter element to push: ");
    scanf("%d", &element);
    enqueue(element);
}

/*
* Implement stack pop using enqueue and dequeue
*/
void pop()
{
    int count = count_elements();
    int i = 0;
    int element;

    while (i < count - 1)
    {
        element = dequeue();
        enqueue(element);
        i++;
    }

    element = dequeue();
    if(element != -1)
    printf("Popped element: %d\n", element);
    else
    printf("Stack is empty\n");
}

/*
Function to display stack
*/
void display()
{
    struct queue *ptr;
    ptr = start;

    if (start == NULL)
    {
        printf("is empty\n");
    }
    else
    {
        printf("elements are: ");
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
    int choice;
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
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}