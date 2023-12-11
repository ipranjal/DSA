/*
Write a program to insert a node at:
a. End of singly linked list
b. Start of singly linked list
c. Middle of a singly linked list.

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

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        new_node->next = start;
        start = new_node;
    }
}

/*
Function to enter new node at the middle of linked list
*/
void insert_middle()
{
    // pre_ptr is pointer to the node after which new node is to be inserted
    // next_ptr is pointer to the node before which new node is to be inserted
    struct node *new_node, *next_ptr, *pre_ptr;
    int pos, i = 1;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    printf("Enter the pos: ");
    scanf("%d", &pos);

    next_ptr = start;
    while (i < pos)
    {
        // Fixing Segmentation fault error when position more than length of linked list
        if (next_ptr == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        pre_ptr = next_ptr;
        next_ptr = next_ptr->next;
        i++;
    }

    pre_ptr->next = new_node;
    new_node->next = next_ptr;
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

/**
 * Main function to run and test program
 */
int main()
{
    int choice;
    while (1)
    {
        printf("1. Insert at end\n");
        printf("2. Insert at start\n");
        printf("3. Insert at middle\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
            insert_middle();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}