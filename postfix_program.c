#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;


int operand(char item)
{
    if( item == '0' || item == '1' || item == '2' || item == '3' || item == '4' || item == '5' || item == '6' || item == '7' || item == '8' || item == '9')
    {
        return 1;
    }
    else return 0;
}


void push(int item)
{
    stack[++top] = item;
}


int Evaluate(int a , int b , char opr)
{
    if (opr == '^')
       return pow(a,b);

    if (opr == '*')
       return a * b ;

    if (opr == '/')
       return a / b ;    

    if (opr == '+')
       return a + b ; 

     if (opr == '-')
       return a - b ;       

}

int pop()
{
    return stack[top--];
}



int main() {
    int a,b,c,result;
    char expression[MAX] = "3 2 5 2 ^ * -",opr;

    int i = 0;
    while(expression[i] != '\0')
    {
        if(operand(expression[i]))
         {
            push(expression[i]);
         }

         if(operator(expression[i]))
         {
            opr =expression[i];
         }

    b = pop();
    a = pop();
    c = Evaluate(a,b,opr);
    push(c);
    }
    result = pop();
    printf("value of postfix is %d",result);
    
    return 0;
}









































#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to check if a character is a digit
int isOperand(char item) {
    return isdigit(item);
}

// Function to push an item onto the stack
void push(int item) {
    stack[++top] = item;
}

// Function to pop an item from the stack
int pop() {
    return stack[top--];
}

// Function to evaluate an operation
int evaluate(int a, int b, char opr) {
    switch(opr) {
        case '^': return pow(a, b);
        case '*': return a * b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
        default: printf("Invalid operator\n"); exit(1);
    }
}

// Function to check if a character is an operator
int isOperator(char item) {
    return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}

int main() {
    char expression[MAX] = "* + 3 4 / 2 7";
    int i = strlen(expression) - 1; // Start from the end of the expression
    int a, b, c, result;
    char opr;

    while (i >= 0) {
        
        if (isOperand(expression[i])) {
            // Push the operand (convert char to int)
            push(expression[i] - '0');
        } else if (isOperator(expression[i])) {
            // Pop two operands for the operator
            a = pop();
            b = pop();
            opr = expression[i];
            // Evaluate the expression and push the result
            c = evaluate(a, b, opr);
            push(c);
        }

        i--;
    }

    // Get the result
    result = pop();
    printf("Value of prefix expression is %d\n", result);

    return 0;
}






























#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to check if a character is a digit
int isOperand(char item) {
    return isdigit(item);
}

// Function to push an item onto the stack
void push(int item) {
    stack[++top] = item;
}

// Function to pop an item from the stack
int pop() {
    return stack[top--];
}

// Function to evaluate an operation
int evaluate(int a, int b, char opr) {
    switch(opr) {
        case '^': return pow(a, b);
        case '*': return a * b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
        default: printf("Invalid operator\n"); exit(1);
    }
}

// Function to check if a character is an operator
int isOperator(char item) {
    return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}

int main() {
    char expression[MAX] = "3 2 5 2 ^ * -";
    int i = 0, a, b, c, result;
    char opr;

    while(expression[i] != '\0') {
        
        if (isOperand(expression[i])) {
            // Push the operand (convert char to int)
            push(expression[i] - '0');
        } else if (isOperator(expression[i])) {
            // Pop two operands for the operator
            b = pop();
            a = pop();
            opr = expression[i];
            // Evaluate the expression and push the result
            c = evaluate(a, b, opr);
            push(c);
        }

        i++;
    }

    // Get the result
    result = pop();
    printf("Value of postfix expression is %d\n", result);

    return 0;
}