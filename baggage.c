#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baggage.h"
#include <time.h>

// Checks if Name is valid or not
int validName(char *name)
{
    int i;
    for (i = 0; i < strlen(name); i++)
    {
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' '))
            return 0;
    }
    return 1;
}

// Checks if Phone is valid or not 10 digits
int validPhone(char *phone)
{
    int i;
    if (strlen(phone) != 10)
        return 0;
    for (i = 0; i < strlen(phone); i++)
    {
        if (!(phone[i] >= '0' && phone[i] <= '9'))
            return 0;
    }
    return 1;
}

// checks if id contains only 6 digits no letters
int validId(char *id)
{
    int i;
    if (strlen(id) != 6)
        return 0;
    for (i = 0; i < strlen(id); i++)
    {
        if (!(id[i] >= '0' && id[i] <= '9'))
            return 0;
    }
    return 1;
}

// hash table functions
void initHashTable(HASH_TABLE *ht) // initialize the hash table
{
    for (int i = 0; i < SIZE; i++)
        ht->table[i] = NULL;
    ht->count = 0;
}

int hashFunction(int key) // compute the hash value of a key
{
    return key % SIZE;
}

void insertHashTable(HASH_TABLE *ht, ITEM it) // insert an item into the hash table
{
    // declare an index variable
    NODE *q;                                // declare a pointer to a node
    int id = atoi(it.id);                   // convert the key to an integer
    int index = hashFunction(id);           // compute the hash value of the key and stores in index
    NODE *p = (NODE *)malloc(sizeof(NODE)); // allocate memory for a new node and store in pointer p
    p->data = it;                           // copy the item data into the node
    p->next = NULL;                         // set the next pointer to NULL

    // check if the linked list is empty
    if (ht->table[index] == NULL)
        // insert the node at the beginning of the linked list
        ht->table[index] = p;
    else
    {
        // traverse the linked list to find the last node
        q = ht->table[index];
        while (q->next != NULL)
        {
            q = q->next;
        }
        // insert the node at the end of the linked list
        q->next = p;
    }
    // increment the number of items in the hash table
    ht->count++;
    // get current time and store in current_time
    getCurrentTime(&p->current_time);
}

struct item searchHashTable(HASH_TABLE *ht, int key) // search for an item in the hash table by key
{
    int index = hashFunction(key); // compute the hash value of the key and store in index
    NODE *p = ht->table[index];    // declare a pointer to table[index]

    // traverse the linked list to find the node with the given key
    while (p != NULL)
    {
        if (atoi(p->data.id) == key)
            // return the item data
            return p->data;
        p = p->next;
    }
    // return an empty item if the key is not found
    struct item it;
    it.id[0] = '\0'; // modify the first character of the id
    return it;
}

void deleteHashTable(HASH_TABLE *ht, int key) // delete an item from the hash table by key
{
    int index = hashFunction(key); // compute the hash value of the key and store in index
    NODE *p = ht->table[index];    // declare a pointer to a node and initialize it to table[index]
    NODE *q = NULL;                // declare a pointer to a node and initialize it to NULL

    // traverse the linked list to find the node with the given key
    while (p != NULL)
    {
        if (atoi(p->data.id) == key)
        {
            // check if the node is the first node
            if (q == NULL)
                // delete first node
                ht->table[index] = p->next;
            else
                // delete the node
                q->next = p->next;
            // free the memory allocated for the node
            free(p);
            printf("Element Deleted\n");
            break;
        }
        q = p;
        p = p->next;
    }
    // decrement the number of items in the hash table
    ht->count--;
}

void displayHashTable(HASH_TABLE *ht) // display all the items in the hash table
{
    int i;   // declare a loop variable
    NODE *p; // declare a pointer to a node
    // display the hash table
    for (i = 0; i < SIZE; i++)
    {
        printf("Room Number:%d\n ", i);
        // traverse the linked list to display the items
        p = ht->table[i];
        if (p == NULL)
            printf("The room is empty.\n");
        while (p != NULL)
        {
            printf("%d:%s %s, ", atoi(p->data.id), p->data.name, p->data.phone);
            printf("Checkin Time: %d:%d:%d\n", p->current_time.hh, p->current_time.mm, p->current_time.ss);
            p = p->next;
        }
        printf("\n");
    }
}

void getCurrentTime(struct check_in *current_time)
{
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    current_time->hh = localTime->tm_hour;
    current_time->mm = localTime->tm_min;
    current_time->ss = localTime->tm_sec;
}