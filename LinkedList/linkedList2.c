#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void traversalLinkedList(struct node *ptr)
{
    while(ptr)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL, *ptr, *t;
    int a;
    t = (struct node*)malloc(sizeof(struct node));
    printf("Enter the first element: ");
    scanf("%d", &t->data);
    t->next = NULL;
    head = t;

    do{
        t = (struct node*)malloc(sizeof(struct node));
        printf("Enter the next element: ");
        scanf("%d", &t->data);
        t->next = NULL;

        //To check from the head everytime
        ptr = head;
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = t;
        
        //Asking to continue or stop
        printf("Do you want to continue? Press 1 for YES and 0 for NO! ");
        scanf("%d", &a);
    }while(a);

    traversalLinkedList(head);

    return 0;
}