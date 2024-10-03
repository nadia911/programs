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

// Function to delete all instances of a node with a given value
struct Node* deleteAllInstances(struct Node* head, int item) {
    struct Node* trav = head;
    struct Node* temp;

    while (trav != NULL) {
        if (trav->data == item) {
            if (trav == head) {
                // If the node to be deleted is the head node
                head = trav->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
                temp = trav;
                trav = trav->next;
                free(temp);
            } else if (trav->next == NULL) {
                // If the node to be deleted is the last node
                trav->prev->next = NULL;
                free(trav);
                break;
            } else {
                // If the node to be deleted is in the middle
                trav->prev->next = trav->next;
                trav->next->prev = trav->prev;
                temp = trav;
                trav = trav->next;
                free(temp);
            }
        } else {
            trav = trav->next;
        }
    }

    return head;
}

int main() 
{
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

    fourth->data = 3; 
    fourth->next = NULL; 
    fourth->prev = third;

    printf("Doubly linked list before deletion\n");
    linkedListTraversal(head);

    int item;
    printf("Enter the item to be deleted: ");
    scanf("%d", &item);

    head = deleteAllInstances(head, item);

    printf("Doubly linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
