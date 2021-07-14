#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};  

int isEmpty(struct node *f)
{
    return f == NULL;
}

int isFull(struct node *f)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    return (n == NULL);
}

void enqueue(struct node **f, struct node **r, int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
    {
        printf("Queue is full!\n");
    }
    else
    {
        n->data = data;
        n->next = NULL;

        if(*f == NULL)
        {
            *f = *r = n;
        }
        else
        {
            (*r)->next = n;
            *r = n;
        }
    }
}

int dequeue(struct node **f)
{
    int val = -1;
    struct node *ptr = *f;
    if(isEmpty(*f))
    {
        printf("Queue Underflow!\n");
        return val;
    }
    else
    {
        *f = (*f)->next;
        val = ptr->data;
        free(ptr);
        return val;
    }   
}

void traversal(struct node *f)
{
    while(f)
    {
        printf("%d-->", f->data);
        f = f->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *f = NULL,*r = NULL;
    enqueue(&f, &r, 3);
    enqueue(&f, &r, 4);
    enqueue(&f, &r, 5);
    enqueue(&f, &r, 6);
    enqueue(&f, &r, 7);
    printf("%d is dequeued!\n", dequeue(&f));
    traversal(f);
    printf("%d is dequeued!\n", dequeue(&f));
    printf("%d is dequeued!\n", dequeue(&f));
    enqueue(&f, &r, 9);
    traversal(f);
    return 0;
}