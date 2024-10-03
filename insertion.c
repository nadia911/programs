#include<stdio.h>
#include<stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *next;  
};

// Initialize the head of the linked list to NULL
struct node* head = NULL;

// Function to print the linked list 
void printList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

// Case 1
struct node * insertAtFirst(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}


// Case 2
struct node * insertAtIndex(struct node *head, int data, int index){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


// Case 3
struct node * insertAtEnd(struct node *head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}



// Case 4
struct node * insertAfterNode(struct node *head, struct node *prevNode, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}



int main() {

    int n ,data,item,index;
    printf(" enter size of linked list :");
    scanf("%d",&n);


    for(int i =1 ; i<=n ; i++)
       {
          printf(" enter data :");
          scanf("%d",&data);
          create_LL(data);  
       }    

     printf(" list before insertion :\n");
    printList();

    printf("enter data you want to enter :\n");
    scanf("%d", &item);
    head = insertAtFirst(head,item);

    printf(" list after insertion at beginning :\n");
    printList();


   printf("enter index at which you want to enter data :\n");
    scanf("%d", &index);
    head = insertAtIndex(head,item,index);


    printf(" list after insertion at INDEX :\n");
    printList();

    head = insertAtEnd(head,item);
    printf(" list after insertion at end :\n");
    printList();


    struct node * third = head->next->next;
    head = insertAfterNode(head,third,item);
    printf(" list after insertion (after given node) :\n");
    printList();

    return 0;
}
