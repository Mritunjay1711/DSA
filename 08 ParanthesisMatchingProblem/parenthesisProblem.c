#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *ch;
};

int isEmpty(struct stack *s)
{
    return (s->top == -1) ? 1 : 0;
}

int isFull(struct stack *s)
{
    return (s->top == s->size - 1) ? 1 : 0;
}

void push(struct stack *s, char c)
{
    if(isFull(s))
    {
        printf("Stack Overflow!");    
    }
    else
    {
        s->top++;
        s->ch[s->top] = c;
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
        return s->ch[s->top--];
    }
}

int paranthesisMatch(char *ex)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = (sizeof(ex)/sizeof(char));
    s->top = -1;
    s->ch = (char*)malloc(s->size * sizeof(char));
    for(int i = 0; ex[i] != '\0'; i++)
    {
        if(ex[i] == '(')
        {
            push(s, '(');
        }
        if(ex[i] == ')')
        {
            if(isEmpty(s))
            {
                return 0;
            }
            else{
                pop(s);
            }
        }
    }
    return isEmpty(s);
}

int main()
{
    char ex[] = {"((2)*5)+(3-4)"};

    if(paranthesisMatch(ex))
    {
        printf("Balanced equation!\n");
    }
    else
        printf("Unblanced equation!\n");   
    return 0;
}