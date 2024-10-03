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

create_ll(45);
create_ll(56);
printlist();

return 0;
}