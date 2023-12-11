/*
Write a program in C to delete a node from any position in a doubly
linked list.

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
Function to delete a node from any position in a doubly linked list
*/
void delete()
{
    struct node *ptr, *preptr;
    int pos, i = 1;

    printf("Enter position to delete node: ");
    scanf("%d", &pos);

    ptr = start;

    // traverse the list till the position
    while (i < pos)
    {
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }

    preptr->next = ptr->next;
    ptr->next->prev = preptr;
    free(ptr);
}

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
Main function to run and test program
*/
int main()
{
    create_list();
    display();
    delete();
    display();
    return 0;
}