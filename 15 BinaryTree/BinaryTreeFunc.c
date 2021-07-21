#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));  // Allocating memory
    n->data = data; // Setting the data
    n->left = NULL;
    n->right = NULL;

    return n;
}


int main()
{
    // Constructing the root node
    struct node *p = createNode(1);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(3);

    // Linking
    p->left = p1;
    p->right = p2;

    printf("%d %d %d\n", p->data, p->left->data, p->right->data);
    
    return 0;
}