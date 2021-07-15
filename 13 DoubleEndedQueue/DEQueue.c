#include<stdio.h>
#include<stdlib.h>


struct DEQueue{
    int r;
    int f;
    int size;
    int *arr;
};

int isEmpty(struct DEQueue *q)
{
    return (q->r == q->f);
}

int isFull(struct DEQueue *q)
{
    return (q->r == q->size - 1);
}

void enqueueF(struct DEQueue *q, int data)
{
    if(q->f == -1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        q->arr[q->f--] = data;
        printf("%d is enqueued at front!\n", data);
    }
}

void enqueueR(struct DEQueue *q, int data)
{
    if(isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
        printf("%d is enqueued at rear!\n", data);
    }
}

int dequeueF(struct DEQueue *q)
{
    int val = -1;
    if(isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return val;
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
        return val;
    }
}

int dequeueR(struct DEQueue *q)
{
    int val = -1;
    if(isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return val;
    }
    else
    {
        val = q->arr[q->r--];
        return val;
    }
}

void traversal(struct DEQueue *q)
{
    for(int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct DEQueue q;
    q.r = q.f = -1;
    q.size = 10;
    q.arr = (int*)malloc(q.size * sizeof(int));
    enqueueR(&q, 2);
    enqueueR(&q, 3);
    enqueueR(&q, 4);
    enqueueR(&q, 5);
    traversal(&q);
    printf("%d is dequeued from front!\n", dequeueF(&q));
    printf("%d is dequeued from front!\n", dequeueF(&q));
    enqueueF(&q, 6);
    enqueueF(&q, 7);
    enqueueF(&q, 8);
    traversal(&q);
    printf("%d is dequeued from rear!\n", dequeueR(&q));
    printf("%d is dequeued from rear!\n", dequeueR(&q));
    traversal(&q);
    return 0;
}