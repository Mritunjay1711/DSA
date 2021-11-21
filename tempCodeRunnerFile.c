#include <stdio.h>
#include <stdlib.h>
struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
};
struct treenode *create(int data)
{
    struct treenode *new = (struct treenode *)malloc(sizeof(struct treenode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void inorder(struct treenode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct treenode *insert(struct treenode *node, int data)
{
    if (node == NULL)
    {
        return create(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    return node;
}
struct treenode *search(struct treenode *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}
struct treenode *min(struct treenode *root)
{
    struct treenode *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct treenode *delete (struct treenode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        //case 1
        if (root->left == NULL && root->right == NULL)
        {
            printf("Invoking!\n");
            free(root);
            root = NULL;
            printf("%u\n", root);
        }
        //case 2
        else if (root->left == NULL)
        {
            struct treenode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct treenode *temp = root;
            root = root->left;
            free(temp);
        }
        //case 3
        else
        {
            struct treenode *temp = min(root->right);
            // printf("%d\n", temp->data);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
        return root;
}
int main()
{
    struct treenode *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    inorder(root);
    printf("\ndelete node 20\n");
    delete (root, 20);
    printf("%u\n", root->left);
    inorder(root);
    return 0;
}