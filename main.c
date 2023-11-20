#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baggage.h"
#include <time.h>

int main()
{
    // declare a hash table
    HASH_TABLE ht;
    // declare an item variable
    ITEM it;
    // declare a key variable
    int key;
    // declare a choice variable
    int choice;
    // initialize the hash table and the priority queue
    initHashTable(&ht);

    // menu driven program to test the hash table and priority queue functions
    do
    {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // read the item details
            printf("Enter the item details\n");
            printf("ID: "); // if letters entered it should be rejected and message to be displayed
            scanf("%s", &it.id);
            getchar();
            if (validId(it.id) == 0)
            {
                printf("Error: Invalid ID\n");
                break;
            }
            // check if the id already exists
            ITEM existingItem = searchHashTable(&ht, atoi(it.id));
            if (existingItem.id[0] != '\0')
            {
                printf("Error: ID already exists\n");
                break;
            }
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
            // insert the item into the hash table
            insertHashTable(&ht, it);
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
                printf("Item details\n");
                printf("%d:%s %s\n ", atoi(it.id), it.name, it.phone);
            }
            else
            {
                printf("Item not found\n");
            }
            break;
        case 3:
            // read the key
            printf("Enter the ID: ");
            scanf("%d", &key);
            // delete the item from the hash table
            deleteHashTable(&ht, key);
            break;
        case 4:
            // display the hash table
            printf("Hash Table\n");
            displayHashTable(&ht);
            break;
        case 5:
            // exit the program
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
