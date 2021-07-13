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

int match(char a, char b)
{
    if(a == '(' && b == ')')
        return 1;
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '<' && b == '>')
        return 1;
    return 0;
}

int paranthesisMatch(char *ch)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = strlen(ch);
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));
    char check;
    for(int i = 0; ch[i] != '\0'; i++)
    {
        if(ch[i] == '(' || ch[i] == '[' || ch[i] == '{' || ch[i] == '<')
        {
            push(s, ch[i]);
        }
        if(ch[i] == ')' || ch[i] == ']' || ch[i] == '}' || ch[i] == '>')
        {
            if(isEmpty(s))
                return 0;
            
            check = pop(s);
            if(!match(check, ch[i]))
                return 0;
        }
    }
    return isEmpty(s);
}

int main()
{
    char *ch = "<1 + {2[8 + 9]- (3/2)}>";

    if(paranthesisMatch(ch))
    {
        printf("Paranthesis matching!\n");
    }
    else
        printf("Paranthesis not matching!\n");
    return 0;
}