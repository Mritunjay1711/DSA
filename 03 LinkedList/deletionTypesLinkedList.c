#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void traversalList(struct node *head)
{
    while(head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


struct node *deletingHead(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}

struct node *deleteInBetween(struct node *head, int index)
{
    struct node *p = head;
    struct node *t = head->next;
    int i = 0;
    while(i < index - 1)
    {
        p = p->next;
        t = t->next;
        i++;
    }
    p->next = t->next;
    free(t);
    return head;
}

struct node *deletingTail(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->next)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Delete a particular value from linked list
struct node *deleteValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *t = head->next;

    while(t->data != value && t->next != NULL)
    {
        p = p->next;
        t = t->next;
    }

    if(t->data == value)
    {
        p->next = t->next;
    }
    free(t);
    return head;
}

int main()
{
    struct node *head = NULL, *t = (struct node*)malloc(sizeof(struct node));
    struct node *p;
    int a;
    printf("Enter the number of elements: ");
    scanf("%d", &a);
    printf("Enter the first element: ");
    scanf("%d", &t->data);
    t->next = NULL;
    head = t;
    while(a - 1)
    {
        struct node *t = (struct node*)malloc(sizeof(struct node));
        printf("Enter the next element: ");
        scanf("%d", &t->data);
        t->next = NULL;
        p = head;
        while(p->next)
            p = p->next;
        
        p->next = t;
        a--;
    }
    traversalList(head);
    // head = deletingHead(head);
    // head = deletingTail(head);
    // head = deleteInBetween(head, 1);
    head = deleteValue(head, 2);
    traversalList(head);    
    return 0;
}