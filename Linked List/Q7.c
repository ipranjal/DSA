/*
Write a program to find the maximum value in a doubly linked list.
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
Function to find the maximum value in a doubly linked list
*/
void find_max()
{
    struct node *ptr;
    int max;
    ptr = start;

    // traverse the list till the end
    while (ptr != NULL)
    {
        // if data of ptr is greater than max
        if (ptr->data > max)
        {
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    printf("Maximum value in the list is %d\n", max);
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
    find_max();
    return 0;
}