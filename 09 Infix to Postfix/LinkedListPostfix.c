#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct node
{
    char data;
    struct node *next;
};
int is_empty(struct node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
void push(struct node **top, char data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = data;

    if (*top == NULL)
        *top = new_node;
    else
    {
        new_node->next = *top;
        *top = new_node;
    }
}
char pop(struct node **top)
{
    if (is_empty(*top))
    {
        printf("\nStack Underflow");
        return 'p';
    }
    else
    {
        char val = (*top)->data;
        struct node *p = *top;
        *top = (*top)->next;
        free(p);
        return val;
    }
}
int precedence(char a)
{
    if (a == '-' || a == '+')
        return 2;
    else if (a == '*' || a == '/')
        return 3;
    else
        return 0;
}
int is_operator(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*')
        return 1;
    else
        return 0;
}
char stacktop(struct node *top)
{
    if(top == NULL)
        return 'p';
    else
    return top->data;
}
char *infix_to_postfix(char *infix)
{
    struct node *top = NULL;
    char *postfix = (char *)malloc(100 * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
        
            if (precedence(infix[i]) > precedence(stacktop(top)))
            {
                push(&top, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(&top);
                j++;
            }
        }
    }
    while (!is_empty(top))
    {
        postfix[j] = pop(&top);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
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
    postfix = infix_to_postfix(infix);
    printf("\n%s", postfix);
    return 0;
}