#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *next;  
};

// Initialize the head of the linked list to NULL
struct node *head = NULL;

// Function to print the linked list 
void printList() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create and add a node to the linked list
void create_LL(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node before or after a given node
void insertNode(struct node* refNode, int data, int before) {
    if (refNode == NULL) {
        printf("Reference node cannot be NULL.\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (before) {
        // Insert before the reference node
        if (head == refNode) {
            // Insert before the head
            newNode->next = head;
            head = newNode;
        } else {
            struct node* temp = head;
            while (temp != NULL && temp->next != refNode) {
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Reference node not found in the list.\n");
                free(newNode);
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    } else {
        // Insert after the reference node
        newNode->next = refNode->next;
        refNode->next = newNode;
    }
}

int main() {
    create_LL(10);  // Creates a node with data 10
    create_LL(20);  // Creates a node with data 20
    create_LL(30);  // Creates a node with data 30
    create_LL(40);  // Creates a node with data 40

    // Print the list
    printf("Original list:\n");
    printList();

    // Insert before a node
    struct node* second = head->next;  // Node with data 20
    printf("Inserting 15 before the node with data 20:\n");
    insertNode(second, 15, 1);  // Insert before the node with data 20

    printList();

    // Insert after a node
    struct node* third = head->next->next;  // Node with data 30
    printf("Inserting 25 after the node with data 30:\n");
    insertNode(third, 25, 0);  // Insert after the node with data 30

    printList();

    // Free the allocated memory
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
