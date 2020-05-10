#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data)
{
    if (root == NULL)
     return createNode(data);
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int data)
{
    // base case
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->data = temp->data;


        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void maxnode(struct node* root)
{
    if(root->right  == NULL)
        printf("%d\n", root->data);
    else
        maxnode(root->right);
}

void inorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root == NULL)
        return;
    printf("%d ->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);
}

void child(struct node* root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        printf("%d",root->data);
        return;
    }
    if(root->left!=NULL)
        child(root->left);
    if(root->right!=NULL)
        child(root->right);
}

int sumnode(struct node* root)
{
    if(root==NULL)
        return 0;
    int sum = root->data + sumnode(root->left) + sumnode(root->right);
    return sum;
}

int main()
{
    struct node *root = NULL;
    int ch,data,sum;
     while(1)
    {
        printf("choice:\n1.insert vertex\n2.inorder\n3.preorder\n4.postorder\n5.min\n6.max\n7.delete vertex\n8.child nodes\n9.sum\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("insert data");
            scanf("%d",&data);
              root =  insert(root,data);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
               root = minValueNode(root);
               printf("%d\n",root->data);
            break;
        case 6:
            if(root!=NULL)
                 maxnode(root);
            break;
        case 7:
            printf("insert data");
            scanf("%d",&data);
            root=deleteNode(root,data);
            break;
        case 8:
            child(root);
            break;
        case 9:
            sum=sumnode(root);
            printf("sum is %d",sum);
            break;
        default:
            exit(0);
            break;
         }
    }
}
