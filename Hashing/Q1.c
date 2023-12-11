/*
WAP to implement Hashing with double hashing as a collision resolution strategy. Your
program should include – Insert, lookup, and delete operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 15
#define PRIME 13


int hashTable[HASH_SIZE];
int values_present = 0;

// initialize hash table with -1
void init()
{
    int i = 0;
    while (i < HASH_SIZE){
        hashTable[i] = -1;
        i++;
    }
}

// hash function for hash table
int hash1(int val){
  return val % HASH_SIZE;
}

// hash function for getting offset
int hash2(int val){
  return PRIME - (val % PRIME);
}

// insert value in hash table
void insert(int value)
{

    if (values_present == HASH_SIZE)
    {
        printf("Hash Table is full \n");
        return;
    }
    //calculate hash key
    int key = hash1(value);
    int offset = hash2(value);

    while (hashTable[key] != -1 )
    {
        key = (key + offset) % HASH_SIZE;
    }

    hashTable[key] = value;
    values_present++;
}

// delete value from hash table
void delete(int value)
{
    int key = hash1(value);
    int offset = hash2(value);

    while (hashTable[key] != value && hashTable[key] != -1)
    {
        key = (key + offset) % HASH_SIZE;
    }

    if (hashTable[key] == -1)
    {
        printf("Value not found \n");
        return;
    }

    hashTable[key] = -1;
    values_present--;
}

// search value in hash table
void lookup(int value)
{
    int key = hash1(value);
    int offset = hash2(value);

    while (hashTable[key] != value && hashTable[key] != -1)
    {
        key = (key + offset) % HASH_SIZE;
    }

    if (hashTable[key] == -1)
    {
        printf("Value not found \n");
        return;
    }

    printf("Value found at index %d \n", key);
}

// display hash table
void display()
{
    int i = 0;
    while (i < HASH_SIZE)
    {
        if (hashTable[i] != -1)
        {
            printf("%d ", hashTable[i]);
        }
        else
        {
            printf("NULL ");
        }
        i++;
    }
    printf("\n");
}

// Main function to test program
int main()
{
    init();
    int choice, value;
    while (1)
    {
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Lookup \n");
        printf("4. Display \n");
        printf("5. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            delete(value);
            break;
        case 3:
            printf("Enter value to lookup: ");
            scanf("%d", &value);
            lookup(value);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice \n");
        }
    }
    return 0;
}

