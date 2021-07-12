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

int precedence(char a)
{
    if(a == '*' || a == '/')
        return 2;
    if(a == '+' || a == '-')
        return 1;
    else 
        return 0;
}

int isOperator(char a)
{
    if(a == '*' || a == '/' || a == '+' || a == '-')
        return 1;
    else 
        return 0;
}

char *infixToPostfix(char *arr)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = strlen(arr);
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));
    char *ans = (char*)malloc(s->size * sizeof(char));
    int j = 0,i = 0;

    
    while(arr[i] != '\0')
    {
        if(!isOperator(arr[i]))
        {
            ans[j] = arr[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(arr[i]) > precedence(stackTop(s)))
            {
                push(s, arr[i]);
                i++;
            }
            else
            {
                ans[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s))
    {
        ans[j] = pop(s);
        j++;
    }
    ans[j] = '\0';
    return ans;
}

int main()
{
    char *infix = {"w*a+b-c*d"};
    char *ans = infixToPostfix(infix);
    printf("%s\n", ans);
    
    return 0;
}