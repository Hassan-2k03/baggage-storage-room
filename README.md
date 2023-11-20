# Baggage Management System

This repository contains a C implementation of a Baggage Management System using hash tables and priority queues. The system allows users to manage baggage items, their owners, and check-in times through a command-line interface.

## Files

### `main.c`

This file contains the main program that utilizes functions defined in `baggage.h` and `baggage.c` to interact with the baggage management system. It presents a menu-driven interface allowing users to insert, search, delete, and display baggage items.

### `baggage.c`

This file includes implementations of functions that perform various operations on the baggage management system. It defines functions for initializing hash tables, inserting, searching, updating, and deleting items, along with functions for validating item details and handling time-related operations.

### `baggage.h`

This header file defines structures, function prototypes, and constants used across the baggage management system. It declares structures for items, nodes in the hash table, check-in times, and priority queues. Additionally, it declares function prototypes for hash table operations, item validations, and time-related functions.

## How to Use

To use this baggage management system:

1. **Compile**: Ensure all files (`baggage.c`, `baggage.h`, `main.c`) are in the same directory. Compile the provided source files using a C compiler. For example:
   
   ```bash
   gcc main.c baggage.c -o baggage_system
   ```

   This command compiles `main.c` and `baggage.c` into an executable named `baggage_system`. Modify the compilation commands according to the specific C compiler and platform used.

2. **Run**: Execute the compiled program:
   
   ```bash
   ./baggage_system
   ```

3. **Menu Options**: Use the displayed menu options to interact with the system. You can perform actions such as inserting new baggage items, searching for items, deleting items, and displaying the contents of the baggage storage.

4. **Input Validation**: The system validates entered data such as ID, name, and phone number. Ensure that inputs adhere to the specified formats for each input type to avoid errors during item insertion.

## Interaction with the Program

Once the program is running, it will display a menu-driven interface in the terminal. Here’s how you can interact with it:

1. **Insert**: Choose option `1` to insert a new baggage item. Enter the details when prompted, such as ID, name, and phone number. Follow the specified formats for each input type.

2. **Search**: Option `2` allows you to search for a baggage item by entering its ID. If found, it displays the item's details (ID, name, phone number, and check-in time). If not found, it indicates that the item is not present.

3. **Delete**: Use option `3` to delete a baggage item by entering its ID. Upon successful deletion, it confirms the removal of the item.

4. **Display**: Option `4` displays all the items stored in the baggage management system. It shows the items organized by room number, along with their details and check-in times.

5. **Exit**: Choose option `5` to exit the program.

### Note

- **Compilation**: Ensure all files (`baggage.c`, `baggage.h`, `main.c`) are in the same directory when compiling the program. Modify the compilation commands according to the specific C compiler and platform used.

- **Interaction**: The program operates via a command-line interface. Follow the displayed menu options (`1` for insertion, `2` for search, `3` for deletion, `4` for display, and `5` to exit) to interact with the baggage management system.

- **Input Validation**: Ensure to input valid details (ID, name, phone number) following the specified formats mentioned in the program to avoid validation errors during item insertion.

---
