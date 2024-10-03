#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define the structure of a node
struct node {
    int data;
    struct node *next;  
};

// Initialize the head of the linked list to NULL
struct node *head = NULL;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;  // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to print only prime numbers in the linked list
void printPrimeNumbers() {
    struct node* temp = head;
    while (temp != NULL) {
        if (isPrime(temp->data)) {  // Check if the number is prime
            printf(" -> %d ", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
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
    create_LL(30);  // Creates a first node with data 30
    create_LL(5);  // Creates a second node with data 60
    create_LL(45);  // Creates a third node with data 45
    create_LL(80);  // Creates a fourth node with data 80
    create_LL(17);  // Adds a prime number
    create_LL(23);  // Adds another prime number
      
    // Now print only prime numbers after each node creation
    printPrimeNumbers();
    return 0;
}
