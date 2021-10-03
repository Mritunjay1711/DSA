#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void createList(node **head, int data)
{
    node *r = *head, *ptr;
    if(r == NULL)
    {
        r = (node*)malloc(sizeof(node));
        r->data = data;
        r->next = NULL;
        *head = r;
    }
    else
    {
        while(r->next)
            r = r->next;
        ptr = (node*)malloc(sizeof(node));
        ptr->data = data;
        ptr->next = NULL;
        r->next = ptr;
    }
}

void traversal(node *head)
{
    while (head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

void printExCancel( node* head, node **newList )
{
    node* start = head;
    node* end;

    while ( start )
    {
        int mod = 0;
        int sum = 0;
        end = start;
        while ( end )
        {
            sum += end->data;
            if ( sum == 0 )
            {
                start = end;
                mod = 1;
                break;
            }
            end = end->next;
        }
        if ( mod == 0 ) {
            createList(newList, start->data);
        }
        start = start->next;
    }
}

int main()
{
    node* head = NULL, *newList;
    int a, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &a);

    for(int i = 1; i <= a; i++)
    {
        printf("Enter the data for the node: ");
        scanf("%d", &data);
        createList(&head, data);
    }
    

    traversal(head);
    printExCancel(head, &newList);
    traversal(newList);
    return 0;
}