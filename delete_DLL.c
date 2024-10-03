#include<stdio.h>
#include<stdlib.h>

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

// Function to delete a node with a specific value
void deleteNode(int data) {
    struct node* temp = head;

    // Case 1: List is empty
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // Traverse the list to find the node to be deleted
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    // Case 2: Node with given data is not found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    // Case 3: Node to be deleted is the head
    if (temp == head) {
        head = head->next;  // Move head to the next node
        if (head != NULL) {
            head->prev = NULL;  // Set prev of new head to NULL
        }
    }
    // Case 4: Node to be deleted is the tail
    else if (temp->next == NULL) {
        temp->prev->next = NULL;  // Set next of the previous node to NULL
    }
    // Case 5: Node to be deleted is in the middle
    else {
        temp->prev->next = temp->next;  // Connect previous node to the next node
        temp->next->prev = temp->prev;  // Connect next node to the previous node
    }

    // Free the memory of the deleted node
    free(temp);
    printf("Node with data %d deleted.\n", data);
}

int main() {
    create_DLL(30);  // Creates a first node with data 30
    create_DLL(60);  // Creates a second node with data 60
    create_DLL(45);  // Creates a third node with data 45
    create_DLL(80);  // Creates a fourth node with data 80
    
    printf("Initial List: ");
    printList();

    deleteNode(30);  // Deleting head
    printf("After deleting head (30): ");
    printList();

    deleteNode(80);  // Deleting tail
    printf("After deleting tail (80): ");
    printList();

    deleteNode(60);  // Deleting a middle node
    printf("After deleting middle node (60): ");
    printList();

    deleteNode(100); // Trying to delete a non-existing node
    return 0;
}
