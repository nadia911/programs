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

// Function to create and add a node to the circular linked list
void create_CLL(int data) {
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

int main() {
    create_CLL(30);  // Creates a node with data 30
    create_CLL(60);  // Creates a node with data 60
    create_CLL(45);  // Creates a node with data 45
    create_CLL(80);  // Creates a node with data 80

    // Print the circular linked list
    printf("Circular Linked List: ");
    printList();  // Expected Output: -> 30 -> 60 -> 45 -> 80 (repeats in a circle)

    return 0;
}
