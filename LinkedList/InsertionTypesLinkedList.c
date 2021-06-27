#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void print(struct node *ptr)
{
    while(ptr)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node *InsertAtBeginning(struct node *ptr, int element)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->next = ptr;
    t->data = element;
    return t;
}

struct node *insertAtIndex(struct node *ptr, int element, int index)
{
    struct node *p = ptr;
    int i = 0;
    while(i < index - 1)
    {
        p = p->next;
        i++;
    }
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = element;
    t->next = p->next;
    p->next = t;
    
    return ptr;
}

struct node *insertAtEnd(struct node *ptr, int element)
{
    struct node *p = ptr;
    struct node *t = (struct node*)malloc(sizeof(struct node));

    while(p->next)
    {
        p = p->next;
    }
    t->data = element;
    p->next = t;
    t->next = NULL;
    
    return ptr;
}

struct node *insertAtNode(struct node *ptr, int element)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = element;
    t->next = ptr->next;
    ptr->next = t;
}

int main()
{
    struct node *head, *second, *third, *fourth;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));


    head->data = 3;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 34;
    fourth->next = NULL;

    print(head);
    // head = InsertAtBeginning(head, 10);
    // head = insertAtIndex(head, 99, 3);
    // head = insertAtEnd(head, 101);
    insertAtNode(second, 202);
    print(head);
    
    return 0;
}