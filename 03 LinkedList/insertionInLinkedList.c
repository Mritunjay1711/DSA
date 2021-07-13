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

void insertAtIndex(struct node *ptr, int index, int element)
{
    int i = 0;
    while(i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = element;
    t->next = ptr->next;
    ptr->next = t;
}

int main()
{
    struct node *head = NULL, *t, *ptr;
    int a;
    t = (struct node*)malloc(sizeof(struct node));
    printf("Enter the first element:");
    scanf("%d", &t->data);
    t->next = NULL;
    head = t;

    do{
        t = (struct node*)malloc(sizeof(struct node));
        printf("Enter the next element: ");
        scanf("%d", &t->data);
        t->next = NULL;

        //To check from head
        ptr = head;
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = t;

        printf("Do you want to continue? 1 for YES and 0 for NO. ");
        scanf("%d", &a);
    }while(a);

    print(head);
    insertAtIndex(head, 2, 10);
    print(head);
    
    return 0;
}