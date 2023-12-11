/*
WAP to implement Hashing with chaining as a collision resolution strategy. Your program
should include – Insert, lookup, and delete operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 15

struct node
{
    int data;
    struct node *next;
};

struct node *hashTable[HASH_SIZE];

// initialise hash table
void init()
{
    for (int i = 0; i < HASH_SIZE; i++)
        hashTable[i] = NULL;
}

int hash(int val){
 return val % HASH_SIZE;
}
// insert into hash table 
void insert(int value)
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = hash(value);

    //check if hash table is empty at that index
    if (hashTable[key] == NULL)
    {
        hashTable[key] = newNode;
    }
    else
    {
        struct node *temp = hashTable[key];
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }
}

// delete from hash table
void delete(int value)
{
    //calculate hash key
    int key = hash(value);

    struct node *delNode = hashTable[key];

    //if hash table is empty
    if (delNode == NULL)
    {
        printf("Value %d is not present\n", value);
        return;
    }
    //if node to be deleted is head node
    if (delNode->data == value)
    {
        hashTable[key] = delNode->next;
        free(delNode);
        return;
    }

    //if node to be deleted is in the chain
    struct node *temp = delNode;
    while (temp->next)
    {
        if (temp->next->data == value)
        {
            delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
            return;
        }
        temp = temp->next;
    }

    printf("Value %d is not present\n", value);
}

void lookup(int value)
{
    //calculate hash key
    int key = hash(value);

    struct node *searchNode = hashTable[key];

    //if hash table is empty
    if (searchNode == NULL)
    {
        printf("Value %d is not present NULL\n", value);
        return;
    }

    //search the list for the value
    while (searchNode)
    {
        if (searchNode->data == value)
        {
            printf("Value %d is present\n", value);
            return;
        }
        searchNode = searchNode->next;
    }

    printf("Value %d is not present\n", value);
}

void display()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        struct node *displayNode = hashTable[i];
        printf("hashTable[%d]-->", i);
        while (displayNode)
        {
            printf("%d -->", displayNode->data);
            displayNode = displayNode->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    init();
    int choice, value;
    while (1)
    {
        printf("\n\n1. Insert\n2. Delete\n3. Lookup\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            delete(value);
            break;
        case 3:
            printf("Enter the value to be searched: ");
            scanf("%d", &value);
            lookup(value);
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