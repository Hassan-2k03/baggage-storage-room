#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10 // size of the hash table

// structure to store the check in time
struct check_in {
    int hh;
    int mm;
    int ss;
};

// structure to store the item information
typedef struct item
{
    char id[6];    // item key
    char name[50]; // item owner name
    char phone[10]; // item owner phone number
} ITEM;

// structure to store the node of the linked list
typedef struct node
{
    struct item data;  // item data
    struct node *next; // pointer to the next node
    struct check_in current_time;  // Add current_time field to the node
} NODE;

// structure to store the hash table
typedef struct hash_table
{
    struct node *table[SIZE]; // array of pointers to linked list nodes
    int count;                // number of items in the hash table
} HASH_TABLE;

// hash table functions
void initHashTable(HASH_TABLE *ht);                     // initialize the hash table
int hashFunction(int key);                              // compute the hash value of a key
void insertHashTable(HASH_TABLE *ht, ITEM it);          // insert an item into the hash table
ITEM searchHashTable(HASH_TABLE *ht, int key);          // search for an item in the hash table by key (id)
void updateHashTable(HASH_TABLE *ht, int key, ITEM it); // update an item in the hash table by key
void deleteHashTable(HASH_TABLE *ht, int key);          // delete an item from the hash table by key
void displayHashTable(HASH_TABLE *ht);                  // display all the items in the hash table

// get the current time

void getCurrentTime(struct check_in *current_time);            

// validation of items
int validName(char *name);   // validate the name of an item
int validPhone(char *phone); // validate the phone number of an item
int validId(char *id);        // validate if id has only numbers