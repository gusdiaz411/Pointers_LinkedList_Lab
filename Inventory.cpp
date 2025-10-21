#include "Inventory.h"
#include <iostream>

// Constructor
// Initialize the linked list to be empty
Inventory::Inventory() : head(nullptr) {}

// Destructor
// Traverse the linked list, deleting all Book objects and Nodes
Inventory::~Inventory() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next; // Save next pointer
        delete current->data;           // Delete Book object
        delete current;                 // Delete Node itself
        current = nextNode;             // Move to next node
    }
}

// Add a book to the inventory in alphabetical order
void Inventory::addBook(Book* bookPtr) {
    if (!bookPtr) {
        std::cout << "Error: Cannot add null book pointer.\n";
        return;
    }

    Node* newNode = new Node(bookPtr);

    // Insert at head if list is empty or new book comes before head
    if (!head || bookPtr->getTitle() < head->data->getTitle()) {
        newNode->next = head;
        head = newNode;
    } else {
        // Traverse to find correct insertion point
        Node* current = head;
        while (current->next && current->next->data->getTitle() < bookPtr->getTitle()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    std::cout << "Book '" << bookPtr->getTitle() << "' added to inventory.\n";
}

// Display all books
void Inventory::displayAll() const {
    // Check if list is empty
    if (!head) {
        std::cout << "No books in inventory.\n";
        return;
    }

    std::cout << "\n=== INVENTORY CONTENTS ===\n";
    Node* current = head;
    int count = 1;
    while (current) {
        std::cout << "Book #" << count << ":\n";
        current->data->displayInfo();
        current = current->next;
        ++count;
    }
}

// Remove a book by title
void Inventory::removeBook(const std::string& title) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->data->getTitle() == title) {
            // Update links
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            // Delete book and node
            std::cout << "Removing book: " << current->data->getTitle() << "\n";
            delete current->data;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }

    std::cout << "Book '" << title << "' not found in inventory.\n";
}

// Search for a book by title
Book* Inventory::findBook(const std::string& title) const {
    Node* current = head;
    while (current) {
        if (current->data->getTitle() == title) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

// Get the number of books
size_t Inventory::getBookCount() const {
    size_t count = 0;
    Node* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

// Check if inventory is empty
bool Inventory::isEmpty() const {
    return head == nullptr;
}
