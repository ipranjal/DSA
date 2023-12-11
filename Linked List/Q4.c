/*
Write a program to merge two sorted Linked lists, L and K.

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
struct node *start1 = NULL;
struct node *start2 = NULL;

/*
Function to merge two sorted Linked lists, L and K
*/
void merge_lists()
{
    struct node *ptr1, *ptr2, *pre_ptr1, *pre_ptr2, *temp_node;
    ptr1 = start1;
    ptr2 = start2;
    pre_ptr1 = NULL;
    pre_ptr2 = NULL;

    // traverse the list till one of the list ends
    while (ptr1 != NULL && ptr2 != NULL)
    {
        // if data of ptr1 is less than data of ptr2
        if (ptr1->data < ptr2->data)
        {
            pre_ptr1 = ptr1;
            ptr1 = ptr1->next;
        }
        // if data of ptr2 is less than data of ptr1
        else if (ptr2->data < ptr1->data)
        {
            temp_node = (struct node *)malloc(sizeof(struct node));
            temp_node->data = ptr2->data;
            temp_node->next = ptr1;
            // if ptr1 is first node of list
            if (pre_ptr1 == NULL)
            {
                start1 = temp_node;
            }
            else
            {
                pre_ptr1->next = temp_node;
            }
            pre_ptr1 = temp_node;
            pre_ptr2 = ptr2;
            ptr2 = ptr2->next;
        }
        // if data of ptr1 is equal to data of ptr2
        else
        {
            pre_ptr1 = ptr1;
            ptr1 = ptr1->next;
            pre_ptr2 = ptr2;
            ptr2 = ptr2->next;
        }
    }

    // if ptr2 is not NULL, append it to list 1
    if (ptr2 != NULL)
    {
        pre_ptr1->next = ptr2;
    }
}

/*
Function to enter new node at the start of linked list
*/
void insert_end1()
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    // Check if list is empty and this is first node
    if (start1 == NULL)
    {
        start1 = new_node;
    }
    else
    {
        ptr = start1;
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
void create_list1()
{
    int i, n;
    printf("Enter number of nodes in linked list 1 (L): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        insert_end1();
    }
}

/*
Function to enter new node at the start of linked list
*/
void insert_end2()
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    // Check if list is empty and this is first node
    if (start2 == NULL)
    {
        start2 = new_node;
    }
    else
    {
        ptr = start2;
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
void create_list2()
{
    int i, n;
    printf("Enter number of nodes in list2 (K): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        insert_end2();
    }
}

/*
Function to display the linked list
*/
void display()
{
    struct node *ptr;
    ptr = start1;
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
    create_list1();
    create_list2();
    merge_lists();
    display();
    return 0;
}