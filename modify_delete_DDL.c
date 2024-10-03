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


// Function to delete the head node
struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

// Function to delete a middle node with a given value
// struct Node* deleteMiddleNode(struct Node* head, int item) {
//     struct Node* trav = head;

//     // Find the node with the given value
//     while (trav != NULL && trav->data != item) {
//         trav = trav->next;
//     }

//     // If the node is not found or it is the head or the last node
//     // if (trav == NULL || trav == head || trav->next == NULL) {
//     //     printf("Item not found in the middle of the list.\n");
//     //     return head;
//     // }

//     // If the node to be deleted is in the middle
//     trav->prev->next = trav->next;
//     trav->next->prev = trav->prev;
//     free(trav);

//     return head;
// }

// Function to delete the tail node
struct Node* deleteTail(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* trav = head;
    while (trav->next != NULL) {
        trav = trav->next;
    }

    if (trav->next == NULL) {
        trav->prev->next = NULL;
        free(trav);
        return head;
    }
   
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
    
    // third->data = 8; 
    // third->next = fourth; 
    // third->prev = second;

    third->data = 1; 
    third->next = NULL; 
    third->prev = second;

    printf("Doubly linked list before deletion\n");
    linkedListTraversal(head);

    int choice;
    printf("Enter 1 to delete head, 2 to delete tail, 3 to delete middle node: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head = deleteHead(head);
            break;
        case 2:
            head = deleteTail(head);
            break;
        // case 3:
        //     printf("Enter the item to be deleted: ");
        //     scanf("%d", &item);
        //     head = deleteMiddleNode(head, item);
        //     break;
        default:
            printf("Invalid choice\n");
    }

    printf("Doubly linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
