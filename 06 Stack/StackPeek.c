#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
{
    return (s->top == -1) ? 1 : 0;
}

int isFull(struct stack *s)
{
    return (s->top == s->size - 1) ? 1 : 0;
}

void push(struct stack *s, int data)
{
    if(isFull(s))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }

}

int pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        return (s->arr[s->top--]);
    }
}

int peek(struct stack *s, int index)
{
    int arrInd = s->top - index + 1;
    if(arrInd < 0)
    {
        printf("Invalid Index!\n");
        return -1;
    }
    else return s->arr[arrInd];
}

int main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));
    
    for(int i = 0; i < s->size; i++)
    {
        int temp;
        printf("Enter the element to push in stack-> ");
        scanf("%d", &temp);
        push(s, temp);
    }
    for(int i = 1; i <= s->top + 1; i++)
    {
        printf("The value at index %d is %d.\n", i, peek(s,i));
    }
    return 0;
}