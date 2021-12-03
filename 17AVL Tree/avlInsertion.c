#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
}node;

int getHeight(node *root)
{
    if(root == NULL)
        return 0;
    return root->height;
}

node *createNode(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

int getBalanceFactor(node *root)
{
    if(!root)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *yl = y->left;

    y->left = x;
    x->right = yl;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *xr = x->right;

    x->right = y;
    y->left = xr;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}


node *insert(node *root, int key)
{
    if(root == NULL)
    {
        return createNode(key);
    }

    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = getBalanceFactor(root);
    
    //Left left case
    if(bf > 1 && key < root->left->data)
        return rightRotate(root);
    
    // Right Right case
    if(bf < -1 && key > root->right->data)
        return leftRotate(root);

    // Left Right case
    if(bf > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right left case
    if(bf < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inOrder(node *root)
{
    if(!root)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(node *root)
{
    if(!root)
        return;
    
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    node *root = NULL;
    int data, a;
    do
    {
        printf("Enter\n1 to insert\n2 for Inorder traversal\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("%d\n", root->data);
            break;
        case 2:
            inOrder(root);
            printf("\n");
            break;
        case 3:
            preOrder(root);
            printf("\n");
            break;
        default:
            break;
        }
    } while (a);
    
    return 0;
}