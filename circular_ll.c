#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;

void addnodeend(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    struct node* temp = head;
    if(head!=NULL)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    else
        newnode->next=newnode;
    head=newnode;
}

void display()
{
    struct node* temp = head;
    while(temp->next!=head);
    {
       printf("%d",temp->data);
       temp=temp->next;
    }
}

int main()
{
    addnodeend(5);
     addnodeend(6);
     addnodeend(7);
   display();
}
