// #include <stdio.h>
// #include <stdlib.h>

// // Define the node structure
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to insert a node after a given node
// void insertAfter(struct Node* prevNode, int data) {
//     if (prevNode == NULL) {
//         printf("The given previous node cannot be NULL\n");
//         return;
//     }

//     struct Node* newNode = createNode(data);
//     newNode->next = prevNode->next;
//     prevNode->next = newNode;
// }

// // Function to insert a node before a given node
// struct Node* insertBefore(struct Node* head, struct Node* nextNode, int data) {
//     if (nextNode == NULL) {
//         printf("The given next node cannot be NULL\n");
//         return head;
//     }

//     struct Node* newNode = createNode(data);

//     // If the node to be inserted is the new head
//     if (head == nextNode) {
//         newNode->next = head;
//         head = newNode;
//         return head;
//     }

//     struct Node* prevNode = head;
//     while (prevNode->next != nextNode && prevNode->next != NULL) {
//         prevNode = prevNode->next;
//     }

//     if (prevNode->next == NULL) {
//         printf("The given next node is not found in the list\n");
//         return head;
//     }

//     newNode->next = prevNode->next;
//     prevNode->next = newNode;
//     return head;
// }

// // Function to traverse the linked list
// void printList(struct Node* head) {
//     struct Node* temp = head;
//     while (temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
// }

// int main() {
//     struct Node* head = createNode(1);
//     struct Node* second = createNode(2);
//     struct Node* third = createNode(3);

//     head->next = second;
//     second->next = third;

//     printf("Original list:\n");
//     printList(head);

//     int p,q;
//     // Insert after the second node
//     insertAfter(second, 4);
//     printf("\nList after inserting 4 after the second node:\n");
//     printList(head);

//     // Insert before the second node
//     head = insertBefore(head, second, 0);
//     printf("\nList after inserting 0 before the second node:\n");
//     printList(head);

//     return 0;
// }



















#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * head = NULL;
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


struct node* insert(struct node* head, struct node* targetNode, int data, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    // 0 - before
    // 1- after
    if (position == 0) 
    {
        
        if (head == targetNode) {
            // Special case: Insert before the head
            newNode->next = head;
            return newNode; // New head
        }

        // Traverse to find the node before the targetNode
        struct node* temp = head;
        while (temp != NULL && temp->next != targetNode) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Target node not found.\n");
            free(newNode);
            return head;
        }
        newNode->next = targetNode;
        temp->next = newNode;

     }
     
      else if (position == 1) 
      {
        // Insert after targetNode
        if (targetNode == NULL) {
            printf("Target node cannot be NULL when inserting after.\n");
            free(newNode);
            return head;
        }

        newNode->next = targetNode->next;
        targetNode->next = newNode;
      } 
    else {
            printf("Invalid position. Use 0 to insert before and 1 to insert after.\n");
            free(newNode);
         }

    return head;
}


struct node* create_LL(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

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
    }
    return newNode;
}
int main() {

    create_LL(10);
    create_LL(20);
    create_LL(30);

    printf("Original List:\n");
    printList(head);

    int data;
    printf("enter data you want to enter :");
    scanf("%d",&data);

    // Insert before the second node
    struct node* secondNode = head->next;
    head = insert(head, secondNode, data, 0);

    printf("List after inserting data before the second node:\n");
    printList(head);

    // Insert after the second node
    head = insert(head, secondNode, data, 1);

    printf("List after inserting data after the second node:\n");
    printList(head);

    return 0;
}
