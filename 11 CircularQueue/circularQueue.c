#include<stdio.h>
#include<stdlib.h>

struct CircularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct CircularQueue *q)
{
    return (q->r == q->f);
}

int isFull(struct CircularQueue *q)
{
    return (q->f == (q->r + 1) % q->size);
}

void enqueue(struct CircularQueue *q, int element)
{
    if(isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = element;
        printf("Queued element: %d\n", element);
    }
}

int dequeue(struct CircularQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue underflow!\n");
        return -1;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        return q->arr[q->f];
    }
}

void traversal(struct CircularQueue *q)
{
    for(int i = q->f + 1; i != q->r + 1; i = (i + 1) % q->size)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct CircularQueue q;
    q.r = q.f = 0;
    q.size = 5;
    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    // enqueue(&q, 4);
    // enqueue(&q, 5);
    printf("%d is dequeued.\n", dequeue(&q));
    printf("%d is dequeued.\n", dequeue(&q));
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 5);
    printf("%d\n", isFull(&q));
    traversal(&q);
    return 0;
}