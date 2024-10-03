#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to traverse the linked list
void linkedListTraversal(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Element: %d\n", temp->data);
        temp = temp->next;
    }
}

// Function to delete a node with a given value
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) {
        return head; // Empty list
    }

    struct Node* trav = head;

    // If head needs to be removed
    if (head->data == value) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(trav);
        return head;
    }

    // Traverse the list to find the node to be deleted
    while (trav != NULL && trav->data != value) {
        trav = trav->next;
    }

    // If the value is not found in the list
    if (trav == NULL) {
        return head;
    }

    // Unlink the node from the linked list
    if (trav->next != NULL) {
        trav->next->prev = trav->prev;
    }
    if (trav->prev != NULL) {
        trav->prev->next = trav->next;
    }

    free(trav);
    return head;
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    // Allocate memory for nodes in the linked list
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // Initialize the doubly linked list
    head->data = 4; 
    head->next = second; 
    head->prev = NULL;

    second->data = 3;
    second->next = third; 
    second->prev = head;
    
    third->data = 8; 
    third->next = fourth; 
    third->prev = second;

    fourth->data = 1; 
    fourth->next = NULL; 
    fourth->prev = third;

    printf("Doubly linked list before deletion\n");
    linkedListTraversal(head);

    head = deleteByValue(head, 3);

    printf("Doubly linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}


