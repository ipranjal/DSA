/*
Write a program to remove duplicate elements from an unsorted Linked List.
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
Function to remove duplicate elements from an unsorted Linked List
*/  
void remove_duplicates()
{
    struct node *ptr1, *ptr2, *pre_ptr2;
    ptr1 = start;
    pre_ptr2 = NULL;

    // traverse the list till one of the list ends
    while (ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        pre_ptr2 = ptr1;
        // traverse the list from ptr1 to end
        while (ptr2 != NULL)
        {
            // if data of ptr1 is equal to data of ptr2
            if (ptr1->data == ptr2->data)
            {
                pre_ptr2->next = ptr2->next;
                free(ptr2);
                ptr2 = pre_ptr2->next;
            }
            else
            {
                pre_ptr2 = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
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
    printf("Linked list before removing duplicates:\n");
    display();
    remove_duplicates();
    printf("Linked list after removing duplicates:\n");
    display();
    return 0;
}