/*
Write a program to create a circular linked list and insert a node at any
position in the list.

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
Function to  insert a node at any position in the list
*/
void insert()
{
    struct node *ptr;
    int pos,data,i= 1;
    
    printf("Enter new data: ");
    scanf("%d", &data);

    printf("Enter position to insert new node: ");
    scanf("%d", &pos);

    ptr = start;

    // traverse the list till the position
    while (i < pos)
    {
        ptr = ptr->next;
        i++;
    }

    ptr->data = data;

}

/**
 * Function to insert a node at the end of the list
 */

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
        // Create empty circular linked list
        struct node *new_node, *ptr;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = 0;
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
    // insert data in any postion
    for (i = 0; i < n; i++)
    {
        insert();
    }
}

/*
Function to display the list
*/
void display()
{
    struct node *ptr;
    ptr = start;

    // traverse the list till the end
    while (ptr->next != start)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

int main()
{
    create_list();
    printf("The list is: ");
    display();
    return 0;
}
