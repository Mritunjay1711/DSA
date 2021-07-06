#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void traversalList(struct node *head)
{
    struct node *p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    }while(p != head);
   printf("\n");
}

struct node *deleteHead(struct node *head)
{
    struct node *p = head;
    struct node *t = head;
    while(t->next != head)
    {
        t = t->next;
    }
    p = p->next;
    t->next = p;
    free(head);
    return p;
}

struct node *deleteAnElement(struct node *head, int element)
{
    struct node *p = head;
    struct node *t = head->next;
    while(t->data != element && t->next != head)
    {
        p = p->next;
        t = t->next;
    }
    p->next = t->next;
    free(t);
    return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *t = head->next;

    for(int i = 0; i < index - 1; i++)
    {
        p = p->next;
        t = t->next;
    }
    p->next = t->next;
    free(t);
    return head;
}

struct node *deleteLast(struct node *head)
{
    struct node *p = head;
    struct node *t = head->next;
    while(t->next != head)
    {
        p = p->next;
        t = t->next;
    }
    p->next = head;
    free(t);
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    head->data = 2;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 19;
    fourth->next = head;
    traversalList(head);
    // head = deleteAnElement(head, 6);
    // head = deleteAtIndex(head, 1);
    // head = deleteHead(head);
    head = deleteLast(head);
    traversalList(head);
    return 0;
}