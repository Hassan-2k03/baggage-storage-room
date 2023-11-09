#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baggage.h"

int main()
{
    HASH_TABLE ht;          // declare a hash table
    PRIORITY_QUEUE pq;      // declare a priority queue
    ITEM it;                // declare an item
    int key;                // declare a key
    int priority;           // declare a priority value
    int choice;             // declare a choice
    int i;                  // declare a loop variable
    initHashTable(&ht);     // initialize the hash table
//    initPriorityQueue(&pq); // initialize the priority queue
    do
    {
        // display the menu
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        // get the choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // process the choice
        switch (choice)
        {
        case 1:
            // get the item details
            printf("Enter the item details:\n");
            printf("ID: ");
            scanf("%d", &it.id);
            printf("Name: ");
            scanf(" %[^\n]s", it.name);
            printf("Phone: ");
            scanf("%s", it.phone);
            printf("Check-in: ");
            scanf("%d:%d", &it.t.hh, &it.t.mm);
            // insert the item into the hash table
            insertHashTable(&ht, it);
            // get the priority value
//            printf("Priority: ");
//            scanf("%d", &priority);
            // insert the item into the priority queue
//            insertPriorityQueue(&pq, it, priority);
            break;
        case 2:
            // get the key
            printf("Enter the key: ");
            scanf("%d", &key);
            // delete the item from the hash table
            deleteHashTable(&ht, key);
            // delete the item from the priority queue
//            deletePriorityQueue(&pq, key);
            break;
        case 3:
            // get the key
            printf("Enter the key: ");
            scanf("%d", &key);
            // search for the item in the hash table
            it = searchHashTable(&ht, key);
            // display the item
            printf("ID: %d\n", it.id);
            printf("Name: %s\n", it.name);
            printf("Phone: %s\n", it.phone);
            printf("Check-in: %d:%d\n", it.t.hh, it.t.mm);
            break;
        case 4:
            // get the key
            printf("Enter the key: ");
            scanf("%d", &key);
            // get the item details
            printf("Enter the item details:\n");
            printf("ID: ");
            scanf("%d", &it.id);
            printf("Name: ");
            scanf("%s", it.name);
            printf("Phone: ");
            scanf("%s", it.phone);
            printf("Check-in: ");
            scanf("%d:%d", &it.t.hh, &it.t.mm);
            // update the item in the hash table
            updateHashTable(&ht, key, it);
            // get the priority value
//            printf("Priority: ");
//            scanf("%d", &priority);
            // update the item in the priority queue
//            updatePriorityQueue(&pq, key, priority);
            break;
        case 5:
            // display the hash table
            displayHashTable(&ht);
            // display the priority queue
//            displayPriorityQueue(&pq);
            break;
        case 6:
            // exit the program
            exit(0);
        default:
            // invalid choice
            printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}