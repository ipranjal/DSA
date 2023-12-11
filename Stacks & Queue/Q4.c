/**
 * Implement a queue using a circular linked list and show all the
operations of the queue.

Author - Pranjal Pandey 
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// pointer to the first node of linked list
struct node *start = NULL;

/**
 * Function to enqueue
*/
void enqueue(int element)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = NULL;

    // Check if list is empty and this is first node
    if (start == NULL)
    {
        start = new_node;
        new_node->next = start;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }
}

/**
 * Function to dequeue
*/
int dequeue()
{
    struct node *ptr;
    ptr = start;
    int element;

    if (start == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        element = start->data;
        // If this is the only data
        if (start->next == start)
        {
            start = NULL;
        }
        else
        {
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = start->next;
            start = start->next;
        }
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
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is: ");
        while (ptr->next != start)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
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
                printf("Dequeued element is %d\n", element);
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