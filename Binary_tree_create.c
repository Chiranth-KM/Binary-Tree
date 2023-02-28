#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node *creating(int val)
{
    struct node *n=malloc (sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

struct node *preorder(struct node *root)
{
    if(root!=NULL)
    {printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);}
}

struct node *postorder(struct node *root)
{
    if(root!=NULL)
    {
    preorder(root->left);
    preorder(root->right);
    printf("%d ",root->data);
    }
}

struct node *inorder(struct node *root)
{
    if(root!=NULL)
    {
    preorder(root->left);
    printf("%d ",root->data);
    preorder(root->right);
    }
}

void main()
{
    struct node *root=creating(2);
    struct node *p1=creating(5);
    struct node *p2=creating(6);

    root->left=p1;
    root->right=p2;

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
}