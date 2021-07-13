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
   
}

struct node *insertAtStart(struct node* head, int data)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    struct node *ptr = head;
    do{
        ptr = ptr->next;
    }while(ptr->next != head);
    p->next = head;
    ptr->next = p;
    return p;
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
    head = insertAtStart(head, 99);
    traversalList(head);
    return 0;
}