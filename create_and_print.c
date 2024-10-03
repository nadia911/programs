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


// Function to create and add a node to the linked list
void create_LL() 
{
    int n ;
    printf(" enter size of linked list :");
    scanf("%d",&n);

    struct node* newNode;
    for(int i =1 ; i<=n ; i++)
     {
          newNode = (struct node*)malloc(sizeof(struct node));
          printf(" enter data :");
          scanf("%d", &newNode->data);
          newNode->next = NULL;

          if (head == NULL) 
          {   // If the list is empty, set the new node as the head
              head = newNode;
          }
         else 
          {
             // If the list is not empty, find the last node and add the new node 
             struct node* temp = head;
             while (temp->next != NULL) 
             {
               temp = temp->next;
             }
             temp->next = newNode;
          } 
 
     }
}

int main() 
{ 
    create_LL();  
    
    printf(" linked list :");
    printList();
    
    return 0;
}
