#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int isEmpty(struct node *top)
{
    return (top == NULL) ? 1 : 0;
}

int isFull(struct node *top)
{
    struct node *s = (struct node*)malloc(sizeof(struct node));
    return (s == NULL) ? 1 : 0;
}

struct node *push(struct node *top, int data)
{
    if(isFull(top))
    {
        printf("Stack Overflow!");
    }
    else
    {
        struct node *p = (struct node*)malloc(sizeof(struct node));
        p->data = data;
        p->next = top;
        top = p;
    }
    return top;
}

//Important
int pop(struct node **top)
{
    int data;
    if(isEmpty(*top))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        data = (*top)->data;
        struct node *n = *top;
        *top = (*top)->next;
        free(n);
    }
    return data;
}

void peek(struct node *top, int index)
{
    for(int i = 1; i < index; i++)
    {
        top = top->next;
    }
    printf("%d\n", top->data);
}

int main()
{
    struct node *top = NULL;
    printf("Empty: %d\n", isEmpty(top));
    top = push(top, 2);
    top = push(top, 4);
    top = push(top, 6);
    top = push(top, 7);
    top = push(top, 9);
    top = push(top, 23);
    printf("%d is popped element.\n", pop(&top));
    peek(top, 5);
    printf("Empty: %d\n", isEmpty(top));
    return 0;
}