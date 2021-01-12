#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void adddata(int data,struct node* v){
    if(data < v->data){
        adddata(data,v->left);
    }
    else{
        adddata(data,v->right);
    }
}

void inorder(struct node* v){
    if(v!=NULL){
        inorder(v->left);
        printf("%d",v->data);
        inorder(v->right);
    }
}
int main(){
    root = (struct node*)malloc(sizeof(struct node));
    root->data = 69;
    root->left = NULL;
    root->right = NULL;
    inorder(root);
}