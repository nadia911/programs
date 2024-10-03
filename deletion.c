#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void printList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void create_LL(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;


    if(head == NULL)
     {
        head = newNode;
     }

     else 
     {
      
        struct node * temp = head;
         while( temp->next != NULL)
           {
              temp = temp->next;
           }
        temp->next = newNode;
     }

}


// Case 1: Deleting the first element from the linked list
struct node * deleteFirst(struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
struct node * deleteAtIndex(struct node * head, int index){
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
struct node * deleteAtLast(struct node * head){
    struct node *p = head;
    struct node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}



// Case 4: Deleting the element with a given value from the linked list  (first occurence)
struct node * deleteByValue(struct node * head, int value){
    struct node *p = head;
    struct node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}



int main()
{
    int n,data,index,value;
    printf("enter size of linked list :");
    scanf("%d", &n);

    for(int i=1; i<=n ; i++)
      {
        printf("enter data : ");
        scanf("%d",&data);
        create_LL(data);
      }

    printf("Linked list before deletion :\n");
    printList();

    head = deleteFirst(head); 
    printf("Linked list after deletion at first :\n");
     printList();

    printf("enter the index at which you want to delete :\n");
    scanf("%d",&index);
    head = deleteAtIndex(head, index);
    printf("Linked list after deletion at index :\n");
    printList();


    head = deleteAtLast(head);
    printf("Linked list after deletion at last :\n");
    printList();


    printf("enter the value you want to delete :\n");
    scanf("%d",&value);
    head = deleteByValue(head,value);
    printf("Linked list after deletion ( given value) :\n");
    printList();
    return 0;
}