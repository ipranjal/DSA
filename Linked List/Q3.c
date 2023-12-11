/*
Write a program to reverse a Linked List from position X to position Y.

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
Function to reverse linked list from position x to position y
*/
void reverse_list()
{
    struct node *ptr, *pre_ptr, *next_ptr,*start_ptr,*pre_start_ptr;
    int x, y, i = 1;
    ptr = start;
    pre_ptr = NULL;

    printf("Enter start position to reverse from:");
    scanf("%d", &x);
    printf("Enter end position to reverse to:");
    scanf("%d", &y);

    // traverse the list till xth node
    while (i < x)
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

    start_ptr = ptr;
    pre_start_ptr = pre_ptr;

    // reverse the list from xth node to yth node
    while (i <= y)
    {
        next_ptr = ptr->next;
        ptr->next = pre_ptr;
        pre_ptr = ptr;
        ptr = next_ptr;
        i++;
    }

    // connect the reversed list to the original list
    start_ptr->next = ptr;
    pre_start_ptr->next = pre_ptr;

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
    reverse_list();
    display();
    return 0;
}