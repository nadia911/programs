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

// Function to delete all nodes with a specific value
void deleteAllNodes(int data) {
    struct node* trav = head;
    struct node* temp;

    // Traverse the entire list to delete all instances of the given value
    while (trav != NULL) {
        // If node matches the data to be deleted
        if (trav->data == data) {
            temp = trav;  // Save reference to the node to be deleted
            
            // Case 1: Node to be deleted is the head
            if (trav == head) {
                head = trav->next;  // Move head to the next node
                if (head != NULL) {
                    head->prev = NULL;  // Set prev of new head to NULL
                }
            }
            // Case 2: Node to be deleted is the tail
            else if (trav->next == NULL) {
                trav->prev->next = NULL;  // Set next of the previous node to NULL
            }
            // Case 3: Node to be deleted is in the middle
            else {
                trav->prev->next = trav->next;  // Connect previous node to the next node
                trav->next->prev = trav->prev;  // Connect next node to the previous node
            }
            
            // Move to the next node before freeing the current one
            trav = trav->next;
            free(temp);  // Free the memory of the deleted node
        } else {
            // If no match, just move to the next node
            trav = trav->next;
        }
    }
}

int main() {
    create_DLL(30);  // Creates a first node with data 30
    create_DLL(60);  // Creates a second node with data 60
    create_DLL(45);  // Creates a third node with data 45
    create_DLL(30);  // Creates a fourth node with data 30
    create_DLL(60);  // Creates a fifth node with data 60
    create_DLL(30);  // Creates a sixth node with data 30

    printf("Initial List: ");
    printList();

    deleteAllNodes(30);  // Deleting all instances of 30
    printf("After deleting all instances of 30: ");
    printList();

    deleteAllNodes(60);  // Deleting all instances of 60
    printf("After deleting all instances of 60: ");
    printList();

    deleteAllNodes(100);  // Trying to delete a non-existing node
    return 0;
}
