/*
Write a program to remove the nth node from a Linked List.

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
function to remove nth node from linked list
*/
void remove_nth_node()
{
    struct node *ptr, *pre_ptr;
    int n,i=1;
    ptr = start;
    pre_ptr = NULL;

    printf("Enter postion to remove element from:");
    scanf("%d", &n);

    // traverse the list till nth node
    while (i < n)
    {
        // make sure that the position do not extend list length
        if (ptr == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        pre_ptr = ptr;
        ptr = ptr->next;
        i++;
    }

    // remove the nth node
    if (pre_ptr == NULL)
    {
        start = ptr->next;
    }
    else
    {
        pre_ptr->next = ptr->next;
    }
    free(ptr);
}

/*
Function to enter new node at the start of linked list
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
Function to create linked list
*/
void create_list()
{
    int i, n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        insert_end();
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

/**
 * Main function to run and test program
 */
int main()
{
    create_list();
    display();
    remove_nth_node();
    display();
    return 0;
}