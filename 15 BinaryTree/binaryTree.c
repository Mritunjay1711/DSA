#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};                

int main()
{
    /**************** Length approach ******************/

    // Constructing root node
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = 1;
    p->left = NULL;
    p->right = NULL;
    struct node *p1, *p2;

    // Constructing second node
    p1 = (struct node*)malloc(sizeof(struct node));
    p1->left = NULL;
    p1->right = NULL;
    p1->data = 2;

    // Constructing second node
    p2 = (struct node*)malloc(sizeof(struct node));
    p2->left = NULL;
    p2->right = NULL;
    p2->data = 3;

    // Linking
    p->left = p1;
    p->right = p2;
    return 0;
}