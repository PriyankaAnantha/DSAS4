// TEST--> IN--> a+b*(c^d-e)^(f+g*h)-i OUT--> abcd^e-fgh*+^*+i-

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Global Variable Declarations */
struct node
{
    char data;
    struct node *prev;
    struct node *next;
};

struct node *L_head = NULL; // Empty List

/* List operations */
void PUSH(char);
char POP();
bool isOperator(char);
int getPrecedence(char);
char* infixToPostfix(char*);

struct node *createNode(char);

int main(void)
{
    char option = '\0';

    printf("------------------------\n");
    printf("---Doubly Linked List as Stack---\n");
    printf("Convert Inx to Postx: C\n");
    printf("EXIT: E\n");
    printf("------------------------\n");

    while (1)
    {

        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'C':
            printf("Enter the Inx expression: ");
            char expression[100];
            scanf(" %[^\n]", expression);
            char* postfixExpression = infixToPostfix(expression);
            printf("Postx expression: %s\n", postfixExpression);
            free(postfixExpression);

            break;

        case 'E':
            printf("Exit\n\n");
            exit(0);

        default:
            printf("Enter correct option\n\n");
        }
    }

    return 0;
}

struct node *createNode(char x)
{
    struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void PUSH(char x)
{
    struct node *newNode = createNode(x);

    newNode->next = L_head;
    newNode->prev = NULL;

    if (L_head != NULL)
    {
        L_head->prev = newNode;
    }
    L_head = newNode;
}

char POP()
{
    if (L_head == NULL)
    {
        printf("Stack is empty\n");
        return '\0';
    }

    char poppedElement = L_head->data;

    struct node *temp = L_head;
    L_head = L_head->next;

    if (L_head != NULL)
    {
        L_head->prev = NULL;
    }

    free(temp);

    return poppedElement;
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int getPrecedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

char* infixToPostfix(char* expression)
{
    int len = strlen(expression);
    char* postfix = (char*)malloc((len + 1) * sizeof(char));
    int postfixIndex = 0;

    for (int i = 0; i < len; i++)
    {
        char ch = expression[i];

        if (isOperator(ch))
        {
            while (L_head != NULL && isOperator(L_head->data) && getPrecedence(L_head->data) >= getPrecedence(ch))
            {
                postfix[postfixIndex++] = POP();
            }
            PUSH(ch);
        }
        else if (ch == '(')
        {
            PUSH(ch);
        }
        else if (ch == ')')
        {
            while (L_head != NULL && L_head->data != '(')
            {
                postfix[postfixIndex++] = POP();
            }
            if (L_head != NULL && L_head->data == '(')
            {
                POP();
            }
        }
        else
        {
            postfix[postfixIndex++] = ch;
        }
    }

    while (L_head != NULL)
    {
        postfix[postfixIndex++] = POP();
    }

    postfix[postfixIndex] = '\0';

    return postfix;
}
