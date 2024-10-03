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

// Function to insert a node at the tail of the doubly linked list
void create_DLL(int data) {
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

// Function to delete the head node of the doubly linked list
void deleteHead() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete the tail node of the doubly linked list
void deleteTail() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    if (temp->next == NULL) {
        // Only one node in the list
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node after a given node
void deleteAfter(struct node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("The given previous node is NULL or there is no node after it.\n");
        return;
    }

    struct node* temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = prevNode;
    }
    free(temp);
}

// Function to delete a node before a given node
void deleteBefore(struct node* nextNode) {
    if (nextNode == NULL || nextNode->prev == NULL) {
        printf("The given next node is NULL or there is no node before it.\n");
        return;
    }

    struct node* temp = nextNode->prev;
    if (temp->prev != NULL) {
        temp->prev->next = nextNode;
    } else {
        head = nextNode;  // Node to delete was the head
    }
    nextNode->prev = temp->prev;
    free(temp);
}

// Function to delete all nodes with a specific value
void deleteAllNodes(int data) {
    struct node* trav = head;
    struct node* temp;

    while (trav != NULL) {
        if (trav->data == data) {
            // Case 1: Node to be deleted is the head
            if (trav == head) {
                head = trav->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
                temp = trav;
                trav = trav->next;
                free(temp);
            }
            // Case 2: Node to be deleted is in the middle
            else if (trav->prev != NULL && trav->next != NULL) {
                trav->prev->next = trav->next;
                trav->next->prev = trav->prev;
                temp = trav;
                trav = trav->next;
                free(temp);
            }
            // Case 3: Node to be deleted is the tail
            else if (trav->next == NULL) {
                trav->prev->next = NULL;
                temp = trav;
                trav = trav->prev;
                free(temp);
            }
        } else {
            trav = trav->next;
        }
    }
}

int main() {
    // Insert nodes into the doubly linked list
    printf("Inserting nodes...\n");
    create_DLL(10);  // List: 10
    create_DLL(20);  // List: 10 <-> 20
    create_DLL(30);  // List: 10 <-> 20 <-> 30
    create_DLL(40);  // List: 10 <-> 20 <-> 30 <-> 40

    // Print list 
    printf("List before deletion:\n");
    printList();  // Expected: 10 <-> 20 <-> 30 <-> 40

    // Perform deletions
    deleteHead();  // Delete node with value 10
    printf("List after deleting head:\n");
    printList();  // Expected: 20 <-> 30 <-> 40

    deleteTail();  // Delete node with value 40
    printf("List after deleting tail:\n");
    printList();  // Expected: 20 <-> 30

    deleteAfter(head);  // Delete node after head (node with value 30)
    printf("List after deleting node after head:\n");
    printList();  // Expected: 20

    // Re-inserting nodes to demonstrate deleteAllNodes
    create_DLL(10);  // List: 20 <-> 10
    create_DLL(30);  // List: 20 <-> 10 <-> 30
    create_DLL(10);  // List: 20 <-> 10 <-> 30 <-> 10
    create_DLL(10);  // List: 20 <-> 10 <-> 30 <-> 10 <-> 10

    // Print list before deleting all nodes with value 10
    printf("List before deleting all instances of 10:\n");
    printList();  // Expected: 20 <-> 10 <-> 30 <-> 10 <-> 10

    deleteAllNodes(10);  // Delete all nodes with value 10
    printf("List after deleting all instances of 10:\n");
    printList();  // Expected: 20 <-> 30

}