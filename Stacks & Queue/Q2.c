/*
WAP to implement an expression using stack. For example:
a. Input: str = “1 3 3 * + 9 -“
b. Output: 1
c. Explanation: If the expression is converted into an infix
expression, it will be 1 + (3 * 3) – 9 = 10 – 9 = 1

Author - Pranjal Pandey
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// implement stack
struct stack
{
    int top;
    int capacity;
    int *array;
};

struct stack *s = NULL;

/**
 * Function to create a stack of given capacity.
 * It initializes size of stack as 0
 */
struct stack *create_stack(int capacity)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = (int *)malloc(s->capacity * sizeof(int));
    return s;
}



/**
 * Function to push an element to the stack
 */
void push(int element)
{
    if (s->top == s->capacity - 1)
    {
        printf("Stack Full\n");
    }
    else
    {
        s->array[++s->top] = element;
    }
}

/**
 * Function to pop an element from the stack
 */
int pop()
{
    if (s->top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    else
    {
        return s->array[s->top--];
    }
}


/**
 * Function to evaluate the postfix expression
 */
int evaluate_postfix(char *str)
{
    int i, len = strlen(str);
    int operand1, operand2, result;
    s = create_stack(len);

    for (i = 0; i < len; i++)
    {
        //If we have a operator, pop the last two numbers and perform the operation
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            operand2 = pop();
            operand1 = pop();
            switch (str[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            push(result);
        }
        else if (str[i] == ' ')
        {
            //If empty character (end of sting) break out of loop and pop the result
           continue;
        }
        else
        {
            //convert to int while pushing 
            push(str[i] - '0');
        }
       
    }
    return pop();
}

/**
 * Main function to run and test program
 */
int main()
{
    char str[100];
    printf("Enter the postfix expression: ");
    scanf("%s", str);
    printf("Result: %d\n", evaluate_postfix(str));
    return 0;
}