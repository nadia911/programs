#include<stdio.h>
#include<stdlib.h>

struct node {
int data ;
struct node * next;
};

struct node *head = NULL;

void printlist()
{
 struct node *temp = head;
 while(temp!= NULL)
 {
    printf("->%d",temp->data);
    temp = temp->next;
 }
}


void create_LL()
{

int n;
printf("enter size of linked list");
scanf("%d",&n);

struct node*newnode;

for(int i=1 ;i<=n;i++)
{ 
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->next= NULL;

    if(head == NULL)
    {
       head = newnode;
    }
    else 
    {
     struct node *temp = head;
     while( temp->next != NULL)
     {
         temp = temp->next;
     }
    temp->next = newnode;
    }
}

}


void create_ll(int data)
{
   struct node*newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = data ;
   newnode->next = NULL;

  if(head == NULL)
    {
       head = newnode;
    }
    else 
    {
     struct node *temp = head;
     while( temp->next != NULL)
     {
         temp = temp->next;
     }
    temp->next = newnode;
    }

}




int main()
{

    
create_LL();
create_ll(45);
printlist();

return 0;
}