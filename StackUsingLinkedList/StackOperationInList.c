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

int peek(struct node *top, int index)
{
    struct node *p = top;
    for(int i = 0; (i < index - 1 && p != NULL); i++)
    {
        p = p->next;
    }
    if(p != NULL)
    {
        return p->data;
    }
    else return -1;
    
}

int stackTop(struct node *top)
{
    return top->data;
}

int stackBottom(struct node *top)
{
    struct node *p = top;
    while(p->next)
    {
        p = p->next;
    }
    return p->data;
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

    for(int i = 1; i <= 5; i++)
    {
        printf("The element at %d index is %d.\n", i, peek(top, i));
    }
    printf("The element at top is %d.\n", stackTop(top));
    printf("The element at bottom is %d.\n", stackBottom(top));
    return 0;
}