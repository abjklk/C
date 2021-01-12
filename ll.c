#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    // struct node* prev;
};

void addbeg(struct node** head,int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(*head==NULL)
    {
        newnode->next=NULL;
        // newnode->prev=NULL;
        *head=newnode;
    }
    else
    {
        newnode->next=*head;
        // newnode->prev=NULL;
        // (*head)->prev=newnode;
        (*head)=newnode;
    }
}

void display(struct node** head)
{
    struct node* temp=*head;
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}


// void displayback(struct node** head)
// {
//     struct node* temp=*head;
//     while (temp->next!=NULL)
//         temp=temp->next;
//     while(temp!=NULL)
//     {
//         printf("%d\t",temp->data);
//         temp=temp->prev;
//     }
// }


void prev(struct node** head){
    if(*head == NULL){
        return;
    }else{
        prev(&(*head)->next);
        printf("%d ",(*head)->data);
    }
}


void rev(struct node** head){
    struct node* prev = NULL;
    struct node* cur = *head;
    while(cur!=NULL){
        struct node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void rev_d(struct node** head){
    struct node* cur = *head;
    while(cur){
        struct node* next = cur->next;
        cur->next = cur->prev;
        cur->prev = next;
        cur = cur->prev;
    } 
    *head = cur->p
}
int main()
{
    struct node* head = NULL;
    addbeg(&head,5);
    addbeg(&head,4);
    addbeg(&head,3);
    display(&head);
    printf("\n");
    // displayback(&head);
    rev(&head);
    display(&head);

}
