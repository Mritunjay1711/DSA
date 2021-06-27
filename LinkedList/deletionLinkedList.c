#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
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

struct node *deleteLinkedList(struct node *head, int index)
{
    struct node *p = head;
    struct node *t = head;
    int i = 0;
    while(i < index - 1)
    {
        p = p->next;
        i++;
    }
   int j = 0;
   while(j < index)
   {
       t = t->next;
       j++;
   }
   p->next = t->next;
    
    return head;
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
    head = deleteLinkedList(head, 3);
    print(head);
    return 0;
}