#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baggage.h"

int main()
{
    // declare a hash table and a priority queue
    HASH_TABLE ht;
    PRIORITY_QUEUE pq;
    // declare an item and a time variable
    ITEM it;
    struct check_in t;
    // declare a key variable
    int key;
    // declare a choice variable
    int choice;
    // initialize the hash table and the priority queue
    initHashTable(&ht);
    //initPriorityQueue(&pq);

    // menu driven program to test the hash table and priority queue functions
    do
    {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // read the item details
            printf("Enter the item details\n");
            printf("Name: ");
            scanf(" %[^\n]s", it.name);
            if (validName(it.name) == 0)
            {
                printf("Error: Invalid Name\n");
                break;
            }
            printf("ID: "); // if letters entered it should be rejected and message to be displayed
            scanf("%s", &it.id);
            getchar();
            if (validId(it.id) == 0)
            {
                printf("Error: Invalid ID\n");
                break;
            }
            printf("Phone: ");
            scanf("%s", it.phone);
            if (validPhone(it.phone) == 0)
            {
                printf("Error: Invalid Phone Number\n");
                break;
            }
            printf("Check-in time (hh:mm): ");
            scanf("%d:%d", &t.hh, &t.mm);
            it.t = t;
            // insert the item into the hash table
            insertHashTable(&ht, it);
            // insert the item into the priority queue
            //insertPriorityQueue(&pq, it);
            break;
        case 2:
            // read the key
            printf("Enter the id: ");
            scanf("%d", &key);
            // search for the item in the hash table
            it = searchHashTable(&ht, key);
            // check if the item is found
            if (it.id[0] != '\0')
            {
                // display the item details
                printf("%d:%s %s %d:%d\n", it.id, it.name, it.phone, it.t.hh, it.t.mm);
            }
            else
            {
                printf("Item not found\n");
            }
            break;
        case 3:
            // read the key
            printf("Enter the key: ");
            scanf("%d", &key);
            // search for the item in the hash table
            it = searchHashTable(&ht, key);
            // check if the item is found
            if (it.id[0] != '\0')
            {
                // read the item details
                printf("Enter the item details\n");
                printf("ID: ");
                scanf("%d", &it.id);
                printf("Name: ");
                scanf(" %[^\n]s", it.name);
                if (validName(it.name) == 0)
                {
                    printf("Error: Invalid Name\n");
                    break;
                }
                printf("Phone: ");
                scanf("%s", it.phone);
                if (validPhone(it.phone) == 0)
                {
                    printf("Error: Invalid Phone Number\n");
                    break;
                }
                printf("Check-in time (hh:mm): ");
                scanf("%d:%d", &t.hh, &t.mm);
                it.t = t;
                // update the item in the hash table
                updateHashTable(&ht, key, it);
                // update the item in the priority queue
                //updatePriorityQueue(&pq, key, it);
            }
            else
            {
                printf("Item not found\n");
            }
            break;
        case 4:
            // read the key
            printf("Enter the ID: ");
            scanf("%d", &key);
            // delete the item from the hash table
            deleteHashTable(&ht, key);
            // delete the item from the priority queue
            //deletePriorityQueue(&pq, key);
            break;
        case 5:
            // display the hash table
            printf("Hash Table\n");
            displayHashTable(&ht);
            // display the priority queue
            //displayPriorityQueue(&pq);
            break;
        case 6:
            // exit the program
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
