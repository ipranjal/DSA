/*
Write a program to create a doubly linked list with functions (inset at
beginning, insert at end, delete from beginning, and delete from end) and
display it in reverse order.

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

/*
Function to enter new node at the end of linked list
*/
void insert_end()
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%d", &new_node->data);
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

/*
Function to enter new node at the start of linked list
*/
void insert_start()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
    }
}

/*
Function to delete node from the end of linked list
*/
void delete_end()
{
    struct node *ptr;
    ptr = start;

    // Check if list is empty
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        // Traverse the list till second last node
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
}

/*
Function to delete node from the start of linked list
*/
void delete_start()
{
    struct node *ptr;
    ptr = start;

    // Check if list is empty
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        start = start->next;
        start->prev = NULL;
        free(ptr);
    }
}

/*
Function to display the linked list
*/
void display()
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    // last pointer is null
    printf("NULL\n");
}

/*
Function to display the linked list in reverse order
*/
void display_reverse()
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->prev;
    }
    // last pointer is null
    printf("NULL\n");
}

/*
main function to run and test program
*/
int main()
{
    int choice;
    while (1)
    {
        printf("1. Insert at end\n");
        printf("2. Insert at start\n");
        printf("3. Delete from end\n");
        printf("4. Delete from start\n");
        printf("5. Display\n");
        printf("6. Display in reverse order\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_end();
            break;
        case 2:
            insert_start();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            delete_start();
            break;
        case 5:
            display();
            break;
        case 6:
            display_reverse();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}