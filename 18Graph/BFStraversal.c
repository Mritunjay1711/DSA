// Uses queue data structure
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

void enqueue(struct queue *q, int element)
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

int dequeue(struct queue *q)
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
    struct queue q;
    q.backInd = q.frontInd = -1;
    q.size = 400;
    q.arr = (int*)malloc(q.size * sizeof(int));
    
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    int i = 0;
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);
    while(!isEmpty(&q))
    {
        int node = dequeue(&q);
        for(int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}