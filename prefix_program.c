#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

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
    if (top == -1) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
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
    int a, b, result;

    while (i >= 0) {
        if (expression[i] == ' ') {
            i--; // Skip spaces
            continue;
        }

        if (isOperand(expression[i])) {
            // Push the operand (convert char to int)
            push(expression[i] - '0');
        } else if (isOperator(expression[i])) {
            // Pop two operands for the operator
            a = pop();
            b = pop();
            // Evaluate the expression and push the result
            result = evaluate(a, b, expression[i]);
            push(result);
        }

        i--;
    }

    // The result of the prefix expression
    result = pop();
    printf("Value of prefix expression is %d\n", result);

    return 0;
}
