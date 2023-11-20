# baggage-storage-room
**Mini project Dsa 3rd semester**

**instructions for execution:**
_gcc baggage.c main.c
gcc a.exe_

# Baggage Management System

This project is a Baggage Management System implemented in C, consisting of a hash table to manage baggage check-ins at an airport.

## Overview

The project contains three main files:
- `baggage.c`: Contains functions for manipulating the hash table.
- `baggage.h`: Header file defining structures, function prototypes, and constants used across the project.
- `main.c`: Implements a menu-driven program to test the functionality of the hash table for baggage management.

## Files Description

### `baggage.c`
This file contains functions for manipulating the hash table :
- **Hash Table Functions**:
  - Initialization, insertion, search, update, deletion, and display of items in the hash table.

### `baggage.h`
Defines structures and function prototypes used in the project:
- Structures for items, nodes of linked lists, along with the hash table.
- Function prototypes for hash table manipulation.

### `main.c`
Implements a menu-driven program to interact with the hash table:
- Offers options for inserting, searching, deleting, and displaying items in the hash table.
- Uses functions from `baggage.c` to perform these operations.

## How to Run

### Prerequisites
- Ensure you have a C compiler installed (e.g., GCC for Unix/Linux or MinGW for Windows).

### Steps
1. **Clone the Repository**
    ```bash
    git clone https://github.com/your-username/baggage-management.git
    cd baggage-management/
    ```

2. **Compile the Code**
    - For Unix/Linux:
        ```bash
        gcc baggage.c main.c -o baggage_manager
        ```
    - For Windows (using MinGW):
        ```bash
        gcc baggage.c main.c -o baggage_manager.exe
        ```

3. **Run the Executable**
    - For Unix/Linux:
        ```bash
        ./baggage_manager
        ```
    - For Windows:
        ```bash
        baggage_manager.exe
        ```

4. **Interact with the Program**
    - Follow the menu-driven options to perform various operations on baggage items:
        - Insert new items.
        - Search for items by ID.
        - Update item details.
        - Delete items.
        - Display the current contents of the hash table.

5. **Exit the Program**
    - Select the exit option from the menu when done.

### Example Commands
- **Compile:**
    ```bash
    gcc baggage.c main.c -o baggage_manager
    ```
- **Run (Unix/Linux):**
    ```bash
    ./baggage_manager
    ```
- **Run (Windows):**
    ```bash
    baggage_manager.exe
    ```

### Note
- Ensure all files (`baggage.c`, `baggage.h`, `main.c`) are in the same directory when compiling.
- Modify the compilation commands according to the specific C compiler and platform used.

