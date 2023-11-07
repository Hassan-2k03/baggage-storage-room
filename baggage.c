#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baggage.h"

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
    int index = hashFunction(it.id);        // compute the hash value of the key and stores in index
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
}

struct item searchHashTable(HASH_TABLE *ht, int key) // search for an item in the hash table by key
{
    int index = hashFunction(key); // compute the hash value of the key and store in index
    NODE *p = ht->table[index];    // declare a pointer to table[index]

    // traverse the linked list to find the node with the given key
    while (p != NULL)
    {
        if (p->data.id == key)
            // return the item data
            return p->data;
        p = p->next;
    }
    // return an empty item if the key is not found
    struct item it;
    it.id = -1;
    return it;
}

void updateHashTable(HASH_TABLE *ht, int key, ITEM it) // update an item in the hash table by key
{
    int index; // declare an index variable
    NODE *p;   // declare a pointer to a node
    // compute the hash value of the key
    index = hashFunction(key);
    // traverse the linked list to find the node with the given key
    p = ht->table[index];
    while (p != NULL)
    {
        if (p->data.id == key)
        {
            // update the item data
            p->data = it;
            break;
        }
        p = p->next;
    }
}

void deleteHashTable(HASH_TABLE *ht, int key) // delete an item from the hash table by key
{
    int index; // declare an index variable
    NODE *p;   // declare a pointer to a node
    NODE *q;   // declare a pointer to a node
    // compute the hash value of the key
    index = hashFunction(key);
    // traverse the linked list to find the node with the given key
    p = ht->table[index];
    q = NULL;
    while (p != NULL)
    {
        if (p->data.id == key)
        {
            // check if the node is the first node
            if (q == NULL)
            {
                // delete first node
                ht->table[index] = p->next;
            }
            else
            {
                // delete the node
                q->next = p->next;
            }
            // free the memory allocated for the node
            free(p);
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
        printf("%d: ", i);
        // traverse the linked list to display the items
        p = ht->table[i];
        while (p != NULL)
        {
            printf("%d %s %s %d -> ", p->data.id, p->data.name, p->data.phone, p->data.check_in);
            p = p->next;
        }
        printf("NULL\n");
    }
}

// priority queue functions

void initPriorityQueue(PRIORITY_QUEUE *pq) // initialize the priority queue
{
    // initialize the priority queue
    pq->root = NULL;
    pq->count = 0;
}

void insertPriorityQueue(PRIORITY_QUEUE *pq, ITEM it, int priority) // insert an item into the priority queue with a priority value
{
    PQ_NODE *p; // declare a pointer to a node
    PQ_NODE *q; // declare a pointer to a node
    // allocate memory for a new node
    p = (PQ_NODE *)malloc(sizeof(PQ_NODE));
    // copy the item data into the node
    p->data = it;
    // set the priority value
    p->priority = priority;
    // set the left and right child pointers to NULL
    p->left = NULL;
    p->right = NULL;
    // check if the priority queue is empty
    if (pq->root == NULL)
    {
        // insert the node as the root node
        pq->root = p;
    }
    else
    {
        // traverse the priority queue to find the last node
        q = pq->root;
        while (q->right != NULL)
        {
            q = q->right;
        }
        // insert the node as the right child of the last node
        q->right = p;
        p->left = q;
    }
    // increment the number of items in the priority queue
    pq->count++;
}

struct item popPriorityQueue(PRIORITY_QUEUE *pq) // pop the item with the highest priority from the priority queue
{
    PQ_NODE *p; // declare a pointer to a node
    PQ_NODE *q; // declare a pointer to a node
    PQ_NODE *r; // declare a pointer to a node
    struct item it;
    // check if the priority queue is empty
    if (pq->root == NULL)
    {
        // return an empty item if the priority queue is empty
        it.id = -1;
        return it;
    }
    else
    {
        // find the node with the highest priority
        p = pq->root;
        q = NULL;
        while (p->right != NULL)
        {
            if (p->priority < p->right->priority)
            {
                q = p->right;
            }
            p = p->right;
        }
        // check if the node with the highest priority is the root node
        if (q == NULL)
        {
            // set the root node to the left child of the root node
            q = pq->root;
            pq->root = pq->root->left;
            if (pq->root != NULL)
            {
                pq->root->right = NULL;
            }
        }
        else
        {
            // set the left child of the node with the highest priority to the right child of the node with the highest priority
            q->left->right = q->right;
            if (q->right != NULL)
            {
                q->right->left = q->left;
            }
        }
        // copy the item data from the node with the highest priority
        it = q->data;
        // free the memory allocated for the node with the highest priority
        free(q);
        // decrement the number of items in the priority queue
        pq->count--;
        // return the item data
        return it;
    }
}

void updatePriorityQueue(PRIORITY_QUEUE *pq, int key, int priority) // update the priority value of an item in the priority queue by key
{
    PQ_NODE *p; // declare a pointer to a node
    // traverse the priority queue to find the node with the given key
    p = pq->root;
    while (p != NULL)
    {
        if (p->data.id == key)
        {
            // update the priority value
            p->priority = priority;
            break;
        }
        p = p->right;
    }
}

void deletePriorityQueue(PRIORITY_QUEUE *pq, int key) // delete an item from the priority queue by key
{
    PQ_NODE *p; // declare a pointer to a node
    PQ_NODE *q; // declare a pointer to a node
    PQ_NODE *r; // declare a pointer to a node
    // traverse the priority queue to find the node with the given key
    p = pq->root;
    q = NULL;
    while (p != NULL)
    {
        if (p->data.id == key)
        {
            // check if the node is the root node
            if (q == NULL)
            {
                // set the root node to the left child of the root node
                q = pq->root;
                pq->root = pq->root->left;
                if (pq->root != NULL)
                {
                    pq->root->right = NULL;
                }
            }
            else
            {
                // set the left child of the node to the right child of the node
                q->left->right = q->right;
                if (q->right != NULL)
                {
                    q->right->left = q->left;
                }
            }
            // free the memory allocated for the node
            free(q);
            break;
        }
        q = p;
        p = p->right;
    }
    // decrement the number of items in the priority queue
    pq->count--;
}

void displayPriorityQueue(PRIORITY_QUEUE *pq) // display all the items in the priority queue
{
    PQ_NODE *p; // declare a pointer to a node
    // display the priority queue
    p = pq->root;
    while (p != NULL)
    {
        printf("%d %s %s %d %d\n", p->data.id, p->data.name, p->data.phone, p->data.check_in, p->priority);
        p = p->right;
    }
}