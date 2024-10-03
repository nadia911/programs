#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node for a circular linked list
struct node {
    int data;
    struct node *next;
};

// Initialize the head of the circular linked list to NULL
struct node *head = NULL;

// Function to print the circular linked list
void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("-> %d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;  // Point to itself
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;  // Point to itself
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to insert a node after a specific node
void insertAfter(int prevData, int data) {
    struct node* temp = head;
    while (temp != NULL && temp->data != prevData) {
        temp = temp->next;
        if (temp == head) {
            printf("Node with data %d not found.\n", prevData);
            return;
        }
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node by its data
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp->data == data) {
        if (temp->next == head) { // Only one node in the list
            free(temp);
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            struct node* toDelete = head;
            head = head->next;
            temp->next = head;
            free(toDelete);
        }
        return;
    }

    // Search for the node to be deleted
    prev = temp;
    temp = temp->next;
    while (temp != head && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Main function to demonstrate insertion and deletion operations
int main() {
    insertAtEnd(30);  // List: 30
    insertAtEnd(60);  // List: 30 <-> 60
    insertAtEnd(45);  // List: 30 <-> 60 <-> 45
    insertAtBeginning(10);  // List: 10 <-> 30 <-> 60 <-> 45
    insertAfter(60, 50);  // List: 10 <-> 30 <-> 60 <-> 50 <-> 45

    // Print the list before deletion
    printf("List before deletion:\n");
    printList();  // Expected: 10 <-> 30 <-> 60 <-> 50 <-> 45

    // Delete a node
    deleteNode(60);  // List: 10 <-> 30 <-> 50 <-> 45
    deleteNode(10);  // List: 30 <-> 50 <-> 45
    deleteNode(45);  // List: 30 <-> 50

    // Print the list after deletion
    printf("List after deletion:\n");
    printList();  // Expected: 30 <-> 50

    return 0;
}
