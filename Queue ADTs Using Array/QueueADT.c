#include<stdio.h>
#include<stdlib.h>

struct queue{
    int frontInd;
    int backInd;
    int size;
    int *arr;
};

int isEmpty(struct queue *q)
{
    return (q->frontInd == q->backInd);
}

int isFull(struct queue *q)
{
    return (q->backInd == q->size - 1);
}

void insert(struct queue *q, int element)
{
    if(isFull(q))
    {
        printf("Queue Full!\n");
    }
    else
    {
        q->backInd++;
        q->arr[q->backInd] = element;
    }

}

int Remove(struct queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("No element to dequeue!\n");
    }
    else
    {    
        q->frontInd++;
        a = q->arr[q->frontInd];
    }
    return a;
}

void traversal(struct queue *q)
{
    for(int i = q->frontInd + 1; i <= q->backInd; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->backInd = q->frontInd = -1;
    q->size = 10;
    q->arr = (int*)malloc(q->size * sizeof(int));
    insert(q, 1);
    insert(q, 2);
    insert(q, 3);
    insert(q, 4);
    insert(q, 5);
    insert(q, 6);
    Remove(q);
    traversal(q);
    return 0;
}