#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void PreOrderTraversal(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void PostOrderTraversal(struct node *root)
{
    if(root != NULL)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void InOrderTraversal(struct node *root)
{
    if(root != NULL)
    {
        InOrderTraversal(root->left);
        printf("%d ", root->data);
        InOrderTraversal(root->right);
    }
}

int main()
{
    /*
            6
          /   \
        2       9
      /  \     /  \
    3     5    8   1
    PreOrderTraversal = 6 2 3 5 9 8 1
    PostOrderTraversal = 3 5 2 8 1 9 6
    InOrderTraversal = 3 2 5 6 8 9 1
    */

   struct node *p = createNode(6);
   struct node *p1 = createNode(2);
   struct node *p2 = createNode(9);
   struct node *p3 = createNode(3);
   struct node *p4 = createNode(5);
   struct node *p5 = createNode(8);
   struct node *p6 = createNode(1);

   // Linking
   p->left = p1;
   p->right = p2;

   p1->left = p3;
   p1->right = p4;

   p2->left = p5;
   p2->right = p6;

   // Traversal
   PreOrderTraversal(p);
   printf("\n");
   PostOrderTraversal(p);
   printf("\n");
   InOrderTraversal(p);
   printf("\n");
    
    return 0;
}