#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if(root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);

    }
    else
        return 1;
}


int main()
{
     /*
            8
          /   \
        5       10
      /  \     /  \
    3     6   9   17
    
    */

   struct node *p = createNode(8);
   struct node *p1 = createNode(5);
   struct node *p2 = createNode(10);
   struct node *p3 = createNode(3);
   struct node *p4 = createNode(6);
   struct node *p5 = createNode(9);
   struct node *p6 = createNode(17);

   // Linking
   p->left = p1;
   p->right = p2;

   p1->left = p3;
   p1->right = p4;

   p2->left = p5;
   p2->right = p6;

   InOrderTraversal(p);
   printf("\n%d\n", isBST(p));
    
    return 0;
}