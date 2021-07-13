#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct Queue *q)
{
    return (q->r == q->size -1);
}

int isEmpty(struct Queue *q)
{
    return (q->f == q->r);
}

void enqueue(struct Queue *q, int element)
{
    if(isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = element;
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void traversal(struct Queue *q)
{
    for(int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    q.f = q.r = -1;
    q.size = 10;
    q.arr = (int*)malloc(q.size * sizeof(int));
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("%d is dequeued from the Queue.\n", dequeue(&q));
    traversal(&q); 
    return 0;
}