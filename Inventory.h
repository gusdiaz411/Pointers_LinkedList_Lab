#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <string>
#include <cstddef> // for size_t

class Inventory {
private:
    // Node structure for linked list
    struct Node {
        Book* data;  // Pointer to a Book object
        Node* next;  // Pointer to the next node

        Node(Book* book) : data(book), next(nullptr) {}
    };

    Node* head; // Head pointer of linked list
                 // When head is nullptr, the list is empty

public:
    // Constructor
    // Pseudocode: Initialize the 'head' pointer to nullptr (empty list)
    Inventory();

    // Destructor
    // Pseudocode: Traverse linked list. For each node:
    // 1. Delete the Book object pointed to by 'data'.
    // 2. Delete the Node itself.
    ~Inventory();

    // Copy constructor and assignment operator (deleted to prevent shallow copying)
    Inventory(const Inventory& other) = delete;
    Inventory& operator=(const Inventory& other) = delete;

    // Add a book to the inventory (maintaining alphabetical order by title)
    // Pseudocode:
    // 1. Check if 'bookPtr' is valid.
    // 2. Dynamically allocate a new Node for the book.
    // 3. Traverse the linked list to find the correct insertion point.
    // 4. Insert the new Node while keeping alphabetical order.
    void addBook(Book* bookPtr);

    // Display all books in the inventory
    // Pseudocode:
    // 1. Check if list is empty (head == nullptr). If so, print "No books".
    // 2. Otherwise, traverse list from head to end.
    // 3. For each node, call displayInfo() on the Book pointer.
    void displayAll() const;

    // Remove a book by title
    // Pseudocode:
    // 1. Traverse the list to find a node with matching title.
    // 2. If found:
    //    a) Update pointers to skip the node.
    //    b) Delete the Book object.
    //    c) Delete the Node.
    // 3. If not found, print "Book not found".
    void removeBook(const std::string& title);

    // Search for a book by title
    // Pseudocode:
    // 1. Traverse the list from head to end.
    // 2. If node's Book title matches input, return pointer to Book.
    // 3. If not found, return nullptr.
    Book* findBook(const std::string& title) const;

    // Get the number of books in the inventory
    // Pseudocode: Traverse the list and count the number of nodes.
    size_t getBookCount() const;

    // Check if inventory is empty
    // Pseudocode: Return true if head == nullptr, false otherwise.
    bool isEmpty() const;
};

#endif // INVENTORY_H
