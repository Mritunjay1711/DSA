#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *createNode(int data)
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
            return 0;
        
        if(prev != NULL && root->data <= prev->data)
            return 0;
        
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

struct node *searchBST(struct node *root, int key)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == key)
        return root;
    else if (root->data > key)
    {
        return searchBST(root->left, key);
    }
    else 
        return searchBST(root->right, key);
    
}

int main()
{
    
     /*
            50
          /   \
        40     60
      /  \     /  \
    20    45   55  70
    
    */

   struct node *p = createNode(50);
   struct node *p1 = createNode(40);
   struct node *p2 = createNode(60);
   struct node *p3 = createNode(20);
   struct node *p4 = createNode(45);
   struct node *p5 = createNode(55);
   struct node *p6 = createNode(70);

   // Linking
   p->left = p1;
   p->right = p2;

   p1->left = p3;
   p1->right = p4;

   p2->left = p5;
   p2->right = p6;

   InOrderTraversal(p);
   
   if(isBST(p))
    printf("\nThis is a BST\n");

   struct node *search = searchBST(p, 55);
   if(search != NULL)
        printf("Found: %d\n", search->data);
    else
        printf("Element not found!\n");
    return 0;
}