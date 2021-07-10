#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void traversalLinkedList(struct node *p)
{
    while(p)
    {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void reversePrint(struct node *p)
{
    if(p == NULL)
    ;
    else
    {
        reversePrint(p->next);
        printf("%d\n", p->data);

    }
    
}


int main()
{
    struct node* head;
    struct node* second;
    struct node* third;

    // Allocating memory
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    //Linking head and second
    head->data = 8;
    head->next = second;

    //Linking second and third
    second->data = 99;
    second->next = third;

    //Terminating the list
    third->data = 23;
    third->next =  NULL;

    traversalLinkedList(head);
    reversePrint(head);

    return 0;
}