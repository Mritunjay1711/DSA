#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *s)
{
    return (s->top == -1);
}

int isFull(struct stack *s)
{
    return (s->top == s->size - 1);
}

void push(struct stack *s, char c)
{
    if(isFull(s))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = c;
    }
}

int pop(struct stack *s)
{
    if(isEmpty(s))
    {
        return 0;
    }
    else
    {
        return s->arr[s->top--];
    }
}

int paranthesisMatch(char *ch)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = strlen(ch);
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));

    for(int i = 0; ch[i] != '\0'; i++)
    {
        if(ch[i] == '(')
        {
            push(s, ch[i]);
        }
        if(ch[i] == ')')
        {
            if(isEmpty(s))
            {
                return 0;
            }
            pop(s);
        }
    }
    return isEmpty(s);
}

int main()
{
    char *ch = {"1*2+((2*3)-(4-9)))"};

    if(paranthesisMatch(ch))
    {
        printf("Paranthesis matching!\n");
    }
    else
    {
        printf("Paranthesis not matching!\n");
    }
    
    return 0;
}