#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *next;
};

struct node *createNode(char data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
        printf("Memory full!");
    else
    {
        n->data = data;
        n->next = NULL;
    }
    return n;
}

int isFull(struct node *top)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
        return 1;
    else 
        return 0;
}

int isEmpty(struct node *top)
{
    return (top == NULL);
}

void push(struct node **top, char c)
{
    struct node *newNode = createNode(c); 
    if(isFull(*top))
        printf("Stack overflow!\n");
    else
    {
        if(isEmpty(*top))
            *top = newNode;
        else 
        {
            newNode->next = *top;
            *top = newNode;
        }
    }
}

char pop(struct node **top)
{
    if(isEmpty(*top))
        printf("Stack underflow!\n");
    else
    {
        char val = (*top)->data;
        struct node *s = *top;
        *top = (*top)->next;
        free(s);
        return val;
    }
}

char stackTop(struct node *top)
{
    if(top == NULL)
        return 'm';
    else
    return top->data;
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

char *infixToPostfix(char *infix)
{
    struct node *top = NULL;
    char *ans = (char*)malloc(sizeof(infix) * sizeof(char));
    int i = 0, j = 0;

    while(infix[i] != '\0')
    {
        if(!isOperator(infix[i]))
        {
            ans[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(top)))
            {
                push(&top, infix[i]);
                i++;
            }
            else
            {
                ans[j] = pop(&top);
                j++;
            }
        }
    }
    while(!isEmpty(top))
    {
        ans[j] = pop(&top);
        j++;
    }
    ans[j] = '\0';
    return ans;
}

int main()
{
    int n;
    printf("\nEnter the size ");
    scanf("%d", &n);
    char *infix = (char *)malloc(n * sizeof(char));
    char *postfix;
    printf("\nEnter the Expression ");
    scanf("%s", infix);
    printf("\nInfix expression : %s", infix);
    postfix = infixToPostfix(infix);
    printf("\n%s", postfix);
    return 0;
}