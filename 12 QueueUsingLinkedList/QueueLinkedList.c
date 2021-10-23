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

int isFull()
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
        printf("%d enqueued!\n", data);
    }
}

void dequeue(struct node **f)
{
    struct node *ptr = *f;
    if(isEmpty(*f))
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        *f = (*f)->next;
        printf("%d dequeued!\n", ptr->data);
        free(ptr);
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
    int a;
    do
    {
        printf("Enter\n1 for checking empty or not\n2 for checking full or not\n3 for Display the elements\n4 for Enqueue\n5 for Dequeue\n0 to exit\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
        {
            if(isEmpty(f))
                printf("Queue is empty!\n");
            else
                printf("Queue is not empty!\n");
            break;
        }
        case 2:
        {
            if(isFull())
                printf("Queue is Full!\n");
            else
                printf("Queue is not Full!\n");
            break;
        }
        case 3:
        {
            traversal(f);
            break;
        }
        case 4:
        {
            int data;
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            enqueue(&f, &r, data);
            break;
        }
        case 5:
        {
            dequeue(&f);
            break;
        }

        }
    }while(a);
    return 0;
}