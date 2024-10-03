#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node for a doubly linked list
struct node {
    int data;
    struct node *next;
    struct node *prev;  // Pointer to the previous node
};

// Initialize the head of the doubly linked list to NULL
struct node *head = NULL;

// Function to print the doubly linked list from start to end
void printList() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create and add a node to the doubly linked list
void create_DLL(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;  // New node's previous pointer will be NULL

    if (head == NULL) {
        // If the list is empty, set the new node as the head
        head = newNode;
    } else {
        // If the list is not empty, find the last node and add the new node 
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;  // Set the new node's prev pointer to the last node
    }
}

// Function to reverse the doubly linked list
void reverseList() {
    struct node *temp = NULL;
    struct node *current = head;

    // Traverse the list and swap the next and prev pointers of each node
    while (current != NULL) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        // Move to the next node in the original list (which is now previous in the reversed list)
        current = current->prev;
    }

    // Update the head to the last node encountered
    if (temp != NULL) {
        head = temp->prev;
    }
}

int main() {
    // Insert nodes into the doubly linked list
    create_DLL(10);  // List: 10
    create_DLL(20);  // List: 10 <-> 20
    create_DLL(30);  // List: 10 <-> 20 <-> 30
    create_DLL(40);  // List: 10 <-> 20 <-> 30 <-> 40

    // Print the list before reversing
    printf("List before reversing:\n");
    printList();  // Expected: 10 <-> 20 <-> 30 <-> 40

    // Reverse the list
    reverseList();

    // Print the list after reversing
    printf("List after reversing:\n");
    printList();  // Expected: 40 <-> 30 <-> 20 <-> 10

    return 0;
}
