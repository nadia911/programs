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

// Function to insert a node at the head of the doubly linked list
void insertAtHead(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert a node at the tail of the doubly linked list
void insertAtTail(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node after a given node
void insertAfter(struct node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

// Function to insert a node before a given node
void insertBefore(struct node* nextNode, int data) {
    if (nextNode == NULL) {
        printf("The given next node cannot be NULL\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;

    if (nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    } else {
        head = newNode;  // If nextNode was the head
    }
    nextNode->prev = newNode;
}

int main() {
    // Insert nodes into the doubly linked list
    printf("Inserting nodes...\n");
    
    insertAtTail(10);  // List: 10
    insertAtTail(20);  // List: 10 <-> 20
    insertAtHead(5);   // List: 5 <-> 10 <-> 20
    
    // Print list after insertions
    printf("List after inserting at head and tail:\n");
    printList();  // Expected: 5 <-> 10 <-> 20


    // Insert nodes after and before existing nodes
    insertAfter(head->next, 15); // List: 5 <-> 10 <-> 15 <-> 20
    insertBefore(head->next->next, 12); // List: 5 <-> 10 <-> 12 <-> 15 <-> 20

    // Print list after additional insertions
    printf("List after inserting in the middle:\n");
    printList();  // Expected: 5 <-> 10 <-> 12 <-> 15 <-> 20

    return 0;
}
