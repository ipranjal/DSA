/*
Write a program in C to delete a node from the middle of a circular linked
list.

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
Function to delete a node from the middle of a circular linked list
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
    free(ptr);
    if(pos==1)
    {
        start = preptr->next;
    }
}

/*
Function to create circular linked list
*/
void create_list()
{
    int i, n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        struct node *new_node, *ptr;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter new data: ");
        scanf("%d", &new_node->data);
        new_node->next = start;

        // Check if list is empty and this is first node
        if (start == NULL)
        {
            start = new_node;
            start->next = start;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
    }
}

/*
Function to display circular linked list
*/
void display()
{
    struct node *ptr;
    ptr = start;

    // traverse the list till the end
    while (ptr->next != start)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

/*
Main function to run program
*/
int main()
{
    create_list();
    printf("Circular linked list before deletion: \n");
    display();
    delete();
    printf("Circular linked list after deletion: \n");
    display();
    return 0;
}