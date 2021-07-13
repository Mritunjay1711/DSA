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

void push(struct stack *s, char ch)
{
    if(isFull(s))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = ch;
    }
}

char pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack UnderFlow!\n");
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

int isOperator(char c)
{
    if(c == '*' || c == '/' || c == '+' || c == '-')
        return 1;
    else 
        return 0;
}

int precedence(char c)
{
    if(c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else 
        return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = strlen(infix);
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));

    char *pos = (char*)malloc(s->size * sizeof(char));
    int i = 0; //To scan infix
    int j = 0; //To fill postfix
    while(infix[i] != '\0')
    {
        if(!isOperator(infix[i]))
        {
            pos[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                pos[j] = pop(s);
                j++;
            }
        }
        
    }

    while(!isEmpty(s))
    {
        pos[j] = pop(s);
        j++;
    }
    pos[j] = '\0';

    return pos;
}

int main()
{
    char *infix = "x-y/z-k*d";
    char *ans = infixToPostfix(infix);
    printf("%s\n", ans);
    return 0;
}