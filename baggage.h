#ifndef BAGGAGE_H // include guard
#define BAGGAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10 // size of the hash table

// structure to store the item information
typedef struct item
{
    int id;         // item key
    char name[50];  // item owner name
    char phone[10]; // item owner phone number
    int check_in;   // item check-in time
} ITEM;

// structure to store the node of the linked list
typedef struct node
{
    struct item data;  // item data
    struct node *next; // pointer to the next node
} NODE;

// structure to store the hash table
typedef struct hash_table
{
    struct node *table[SIZE]; // array of pointers to linked list nodes
    int count;                // number of items in the hash table
} HASH_TABLE;

// structure to store the node of the priority queue
typedef struct pq_node
{
    struct item data;      // item data
    int priority;          // item priority value
    struct pq_node *left;  // pointer to the left child
    struct pq_node *right; // pointer to the right child
} PQ_NODE;

// structure to store the priority queue
typedef struct priority_queue
{
    struct pq_node *root; // pointer to the root node
    int count;            // number of items in the priority queue
} PRIORITY_QUEUE;

// hash table functions
void initHashTable(HASH_TABLE *ht);                            // initialize the hash table
int hashFunction(int key);                                     // compute the hash value of a key
void insertHashTable(HASH_TABLE *ht, ITEM it);                 // insert an item into the hash table
ITEM searchHashTable(HASH_TABLE *ht, int key);                 // search for an item in the hash table by key (id)
void updateHashTable(HASH_TABLE *ht, int key, ITEM it); // update an item in the hash table by key
void deleteHashTable(HASH_TABLE *ht, int key);                 // delete an item from the hash table by key
void displayHashTable(HASH_TABLE *ht);                         // display all the items in the hash table

// priority queue functions
void initPriorityQueue(PRIORITY_QUEUE *pq);                          // initialize the priority queue
void insertPriorityQueue(PRIORITY_QUEUE *pq, ITEM it, int priority); // insert an item into the priority queue with a priority value
ITEM popPriorityQueue(PRIORITY_QUEUE *pq);                           // pop the item with the highest priority from the priority queue
void updatePriorityQueue(PRIORITY_QUEUE *pq, int key, int priority); // update the priority value of an item in the priority queue by key
void deletePriorityQueue(PRIORITY_QUEUE *pq, int key);               // delete an item from the priority queue by key
void displayPriorityQueue(PRIORITY_QUEUE *pq);                       // display all the items in the priority queue

#endif