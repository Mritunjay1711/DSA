#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
}; 

void traversal(struct node *head)
{
    struct node *p = head;
    while(p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d ", p->data);
    printf("\n");
    if(p->next == NULL)
    {
        while(p->prev != NULL)
        {
            printf("%d ", p->data);
            p = p->prev;
        }
    }
    printf("%d ", p->data);
    printf("\n");
}

int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth = (struct node*)malloc(sizeof(struct node));

    //Linking
    head->data = 7;
    head->prev = NULL;
    head->next = second;

    second->data = 16;
    second->prev = head;
    second->next = third;

    third->prev = second;
    third->data = 9;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 12;
    fourth->next = NULL;
    traversal(head);
    return 0;
}