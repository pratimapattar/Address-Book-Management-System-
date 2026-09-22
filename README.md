# Address Book Management System

A menu-driven **Address Book Management System developed in C**. The application allows users to manage contact information and provides features such as adding, searching, editing, deleting, sorting, and storing contacts.

## Features

* Add a new contact
* Search for a contact
* Edit existing contact details
* Delete a contact
* Display all contacts
* Sort contacts
* Validate contact details
* Check for duplicate contacts
* Store contact information in a CSV file
* Load saved contacts when the application starts

## Technologies Used

* **Programming Language:** C
* **Compiler:** GCC
* **Operating System:** Linux
* **Data Storage:** CSV file

## C Concepts Used

This project demonstrates practical usage of:

* Structures
* Arrays
* Pointers
* Functions
* Strings
* File handling
* Dynamic memory allocation
* Modular programming
* Input validation

## Project Structure

```text
Address-Book-Management-System/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── populate.c
├── populate.h
├── contact.csv
├── Documentation.txt
└── README.md
```

## How to Compile

Clone the repository and navigate to the project directory.

Compile the source files using GCC:

```bash
gcc *.c -o addressbook
```

## How to Run

Run the executable:

```bash
./addressbook
```

## Application Flow

```text
Start
  |
  v
Display Menu
  |
  +---- Add Contact
  |
  +---- Search Contact
  |
  +---- Edit Contact
  |
  +---- Delete Contact
  |
  +---- Display Contacts
  |
  +---- Sort Contacts
  |
  +---- Save Contacts
  |
  +---- Exit
```

## Learning Outcomes

Through this project, I gained practical experience in:

* Developing a menu-driven C application
* Working with structures and pointers
* Handling files for persistent data storage
* Splitting a project into multiple source and header files
* Implementing validation and duplicate checking
* Compiling and executing C programs in a Linux environment
* Debugging and testing a multi-file C project

## Author

**Pratima C Pattar**

Graduate ECE | Embedded Systems & IoT

