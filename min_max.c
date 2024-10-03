#include<stdio.h>
#include<stdlib.h>
#include<limits.h>  // For INT_MIN and INT_MAX

// Define the structure of a node
struct node {
    int data;
    struct node *next;  
};

// Initialize the head of the linked list to NULL
struct node *head = NULL;

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

// Function to find the minimum value in the linked list
int findMin() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return INT_MAX;
    }

    int min = INT_MAX;
    struct node* temp = head;
    
    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

// Function to find the maximum value in the linked list
int findMax() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return INT_MIN;
    }

    int max = INT_MIN;
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int main() {
    create_LL(30);  // Adds 30 to the linked list
    create_LL(60);  // Adds 60 to the linked list
    create_LL(45);  // Adds 45 to the linked list
    create_LL(80);  // Adds 80 to the linked list
    create_LL(17);  // Adds 17 to the linked list
    create_LL(23);  // Adds 23 to the linked list

    int min = findMin();  // Find the minimum value in the linked list
    int max = findMax();  // Find the maximum value in the linked list

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
