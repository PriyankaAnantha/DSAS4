/*1. Stack Implementation using Arrays */
// use alt+z to text wrap//

#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */

int S_size = 5; // Size of the stack. why are we defining the size of the stack? Because we are using an array to implement the stack.
int S_top = -1; // Top of the stack. it is initialized to -1 because the stack is empty. elements are inserted from index 0. we are defining the top of the stack. why? Because we are using an array to implement the stack.

/* Stack operations */
void display(int[]); // Display the stack elements. what is int[]? It is an array of integers.
void PEEK(int[]); // Display the top element of the stack. what is int[]? It is an array of integers. Why is it not returning anything? Because it is just displaying the top element. It is not removing the top element.
void PUSH(int[], int); // Insert an element into the stack. what is int[]? It is an array of integers. What is int? It is the element to be inserted. so basically PUSH is a function that takes an array and an integer as input. 

int POP(int[]); // Remove the top element from the stack. what is int[]? It is an array of integers. What is int? It is the element to be removed. so basically POP is a function that takes an array as input and returns an integer. why is it returning an integer? Because the element that is removed is returned to the caller of the function. 
int STACK_EMPTY(int[]); // Check whether the stack is empty. what is int[]? It is an array of integers. Why is it returning an integer? Because it returns 1 if the stack is empty and 0 if the stack is not empty.

int main(void)
{
    int S[5] = {0}; // S is an array of size 5 and initialized to 0. This is our stack.
    int x = 0; // x is the element to be inserted into the stack. 

    char option = '\0'; // option is the user input to choose the operation. What operation to perform on the stack. Menu driven program.

    printf("-----------------\n"); 
    printf("---STACK  Menu---\n"); 
    printf("Show: S\n");
    printf("PUSH: I\n");
    printf("POP : D\n");
    printf("PEEK : L\n");
    printf("EXIT: E\n");
    printf("-----------------\n");

    while (1) // Infinite loop to keep the program running until the user exits. 
    {

        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'S':
            printf("Displaying Stack\n\n");
            display(S);

            break;

        case 'I':
            printf("Enter element to insert:");
            scanf("%d", &x);
            PUSH(S, x);

            break;

        case 'D':
            x = POP(S);

            break;

        case 'L':
            PEEK(S);
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

void display(int S[])
{
    /* First, check whether stack is empty (underflow). */
    /* If it is not empty, then print the contents of stack */
    if (STACK_EMPTY(S))
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = 0; i <= S_top; i++)
        {
            printf("%d ", S[i]);
        }
        printf("\n");
    }
}

void PUSH(int S[], int x)
{
    /* Check whether stack is full (overflow). */
    /* If not full, we can push the data. */
    if (S_top == (S_size-1))
    {
        printf("Stack is full\n");
    }
    else
    {
        S_top = S_top + 1;
        S[S_top] = x;
        display(S);
    }
}

int STACK_EMPTY(int S[])
{
    /* Check S_top is -1 */
    if (S_top == -1) // BEWARE, NOT ASSIGNMENT OPERATOR, USE COMPARISON OPERATOR
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int POP(int S[])
{
    /* Check whether stack is empty (underflow) */
    /* If not empty, then we can pop the top element */
    /* Note: The top element is present at S_top - 1 */
    if (STACK_EMPTY(S))
    {
        printf("Stack is empty, underflow\n");
        return -1; // Why are we returning -1? Because the stack is empty. There is no element to remove. So, we are returning -1 to indicate that the stack is empty.
    }
    else
    {
        int x = S[S_top]; // x is the top element of the stack.  S[S_top] means the top element of the stack. how do we know that S[S_top] is the top element of the stack? Because S_top is the index of the top element of the stack. so basically s_top is the index variable of the top element of the stack.
        S_top = S_top - 1; // S_top is decremented by 1. Because the top element is removed. So, the top element is decremented by 1.
        display(S); // Display the stack after removing the top element. Why are we displaying the stack after removing the top element? To show the updated stack to the user.
        return x; // Return the top element that is removed. Why are we returning the top element that is removed? Because the caller of the function may need the top element that is removed. So, we are returning the top element that is removed.
    }
}

void PEEK(int S[])
{
    /* Check whether stack is empty. */
    /* If not empty, then print then print the top element */
    if (STACK_EMPTY(S))
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Top element: %d\n", S[S_top]);
    }
    return;
}
