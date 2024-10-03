#include<stdio.h>
#include<stdlib.h>

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
    while (temp != NULL) {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to count no. of nodes
void countList() {
    struct node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("no of nodes  = %d",count);
}


// Function to create and add a node to the linked list
void create_LL(int data) {
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
}

int main() {
    create_LL(30);  // Creates a first node with data30
    create_LL(60);  // Creates a second node with data 60
    create_LL(45);  // Creates a third node with data 45
    create_LL(80);  // Creates a fourth node with data 80
    // Now print the updated list
    printList();
    countList();
    return 0;
}
