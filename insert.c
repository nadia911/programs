// #include<stdio.h>
// #include<stdlib.h>

// // Define the structure of a node
// struct node {
//     int data;
//     struct node *next;  
// };

// struct node * head = NULL;

// // Function to print the linked list 
// void printList() {
//     struct node* temp = head;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// struct node* create_LL(int data) {
//     struct node* newNode = (struct node*)malloc(sizeof(struct node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (head == NULL) {
//         // If the list is empty, set the new node as the head
//         head = newNode;
//         return newNode;
//     } else {
//         // If the list is not empty, find the last node and add the new node 
//         struct node* temp = head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
//     return newNode;
// }

// // Case 1
// struct node * insertAtFirst(struct node *head, int data){
//     struct node * ptr = (struct node *) malloc(sizeof(struct node));
//     ptr->data = data;

//     ptr->next = head;
//     return ptr; 
// }


// // Case 2
// struct node * insertAtIndex(struct node *head, int data, int index){
//     struct node * ptr = (struct node *) malloc(sizeof(struct node));
//     ptr->data = data;
//     struct node * p = head;
//     int i = 0;

//     while (i!=index-1)
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }


// // Case 3
// struct node * insertAtEnd(struct node *head, int data){
//     struct node * ptr = (struct node *) malloc(sizeof(struct node));
//     ptr->data = data;
//     struct node * p = head;

//     while(p->next!=NULL){
//         p = p->next;
//     }
//     p->next = ptr;
//     ptr->next = NULL;
//     return head;
// }



// // Case 4
// struct node * insertAfterNode(struct node *head, struct node *prevNode, int data){
//     struct node * ptr = (struct node *) malloc(sizeof(struct node));
//     ptr->data = data;

//     ptr->next = prevNode->next;
//     prevNode->next = ptr;
//     return head;
// }



// int main() {

//     int n ,data,item,index;
//     struct node * head = create_LL(10);
//     struct node * second = create_LL(20);
//     struct node * third = create_LL(30);
//     struct node * fourth = create_LL(40);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
    

//      printf(" list before insertion :\n");
//     printList();

//     printf("enter data you want to insert:\n");
//     scanf("%d", &item);
//     head = insertAtFirst(head,item);

//     printf(" list after insertion at beginning :\n");
//     printList();


//    printf("enter index at which you want to enter data :\n");
//     scanf("%d", &index);
//     head = insertAtIndex(head,item,index);


//     printf(" list after insertion at INDEX :\n");
//     printList();

//     head = insertAtEnd(head,item);
//     printf(" list after insertion at end :\n");
//     printList();


//     head = insertAfterNode(head,third,item);
//     printf(" list after insertion (after given node) :\n");
//     printList();

//     return 0;
// }








#include<stdio.h>
#include<stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *next;  
};

// Initialize the head pointer to NULL
struct node *head = NULL;

// Function to print the linked list 
void printList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create and add a node to the linked list
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

// Function to insert a node at the beginning of the list
struct node* insertAtFirst(struct node* head, int data){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr; 
}

// Function to insert a node at a specific index in the list
struct node* insertAtIndex(struct node* head, int data, int index){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;
    int i = 0;

    while (i != index-1) {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Function to insert a node at the end of the list
struct node* insertAtEnd(struct node* head, int data){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Function to insert a node after a specific node in the list
struct node* insertAfterNode(struct node* head, struct node* prevNode, int data){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main() {
    int n, data, item, index;

    // Creating the linked list using create_LL function
    create_LL(10);
    create_LL(20);
    create_LL(30);
    create_LL(40);

    printf("List before insertion:\n");
    printList();

    // Insert at the beginning
    printf("Enter data you want to insert at the beginning:\n");
    scanf("%d", &item);
    head = insertAtFirst(head, item);

    printf("List after insertion at the beginning:\n");
    printList();

    // Insert at a specific index
    printf("Enter index at which you want to insert data:\n");
    scanf("%d", &index);
    head = insertAtIndex(head, item, index);

    printf("List after insertion at index %d:\n", index);
    printList();

    // Insert at the end
    head = insertAtEnd(head, item);
    printf("List after insertion at the end:\n");
    printList();

    // Insert after a specific node
    struct node* third = head->next->next; // This points to the third node (30)
    head = insertAfterNode(head, third, item);
    printf("List after insertion after the given node:\n");
    printList();

    return 0;
}










