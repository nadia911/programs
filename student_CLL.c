#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node for a circular linked list
struct node {
    char name[50];
    int age;
    int marks;
    struct node *next;
};

// Initialize the head of the circular linked list to NULL
struct node *head = NULL;

// Function to create and add a node to the circular linked list
void create_CLL(char *name, int age, int marks) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->marks = marks;
    
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

// Function to display students with marks less than 100
void displayLowMarks() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    do {
        if (temp->marks < 100) {
            printf("Name: %s, Age: %d, Marks: %d\n", temp->name, temp->age, temp->marks);
        }
        temp = temp->next;
    } while (temp != head);
}

// Main function to demonstrate the circular linked list operations
int main() {
    // Insert nodes into the circular linked list
    create_CLL("Alice", 20, 95);
    create_CLL("Bob", 22, 105);
    create_CLL("Charlie", 21, 85);
    create_CLL("David", 23, 75);
    create_CLL("Eve", 24, 99);       // New student
    create_CLL("Frank", 25, 100);    // New student

    // Display students with marks less than 100
    printf("Students with marks less than 100:\n");
    displayLowMarks();  // Expected Output: Alice, Charlie, David, Eve

    return 0;
}
