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

char pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        return s->arr[s->top--];
    }
}

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int match(char a, char b)
{
    if(a == '{' && b == '}')
        return 1;
    else if (a == '(' && b == ')')
    {
        return 1;
    }
    else if(a == '[' && b == ']')
    {
        return 1;
    }
    else 
        return 0;
    
}

int paranthesisMatch(char *ex)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = strlen(ex);
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));
    char popped_ch;

    for(int i = 0; ex[i] != '\0'; i++)
    {
        if(ex[i] == '[' || ex[i] == '{' || ex[i] == '(')
        {
            push(s, ex[i]);
        }
        else if(ex[i] == ']' || ex[i] == '}' || ex[i] == ')')
        {
            if(isEmpty(s))
            {
                return 0;
            }
            popped_ch = pop(s);
            if(!match(popped_ch,ex[i]))
                return 0;
        }
    }
    return isEmpty(s);
}

int main()
{
    char *ex = "[34-[({3*5}) +{2+2}]]";

    if(paranthesisMatch(ex))
    {
        printf("The paranthesis is matching!\n");
    }
    else
    {
        printf("The paranthesis is not matching!\n");
    }
    return 0;
}