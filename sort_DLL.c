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

// Function to insert a node in sorted order
void sortedInsert(struct node** sortedHead, struct node* newNode) {
    struct node* current;

    // If the list is empty or the new node should be inserted at the beginning
    if (*sortedHead == NULL || (*sortedHead)->data >= newNode->data) {
        newNode->next = *sortedHead;
        newNode->prev = NULL;
        if (*sortedHead != NULL) {
            (*sortedHead)->prev = newNode;
        }
        *sortedHead = newNode;
    } else {
        // Find the correct position to insert the new node
        current = *sortedHead;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to perform Insertion Sort on the doubly linked list
void insertionSort() {
    struct node* sortedHead = NULL;
    struct node* current = head;

    // Traverse the original list and insert nodes into sortedHead
    while (current != NULL) {
        struct node* nextNode = current->next;
        // Remove current from the original list
        current->next = NULL;
        current->prev = NULL;
        // Insert current node into the sorted list
        sortedInsert(&sortedHead, current);
        // Move to the next node in the original list
        current = nextNode;
    }

    // Update the head to point to the sorted list
    head = sortedHead;
}

int main() {
    // Insert nodes into the doubly linked list
    create_DLL(40);  // List: 40
    create_DLL(10);  // List: 40 <-> 10
    create_DLL(30);  // List: 40 <-> 10 <-> 30
    create_DLL(20);  // List: 40 <-> 10 <-> 30 <-> 20

    // Print the list before sorting
    printf("List before sorting:\n");
    printList();  // Expected: 40 <-> 10 <-> 30 <-> 20

    // Sort the list
    insertionSort();

    // Print the list after sorting
    printf("List after sorting:\n");
    printList();  // Expected: 10 <-> 20 <-> 30 <-> 40

    return 0;
}
