#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int val) {
    if (top < SIZE - 1)
        stack[++top] = val;
}

int pop() {
    if (top >= 0)
        return stack[top--];
    return 0;
}

int size() {
    return top + 1;
}

int operation(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evalPostfix(char expr[]) {
    top = -1;
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {  
        if (isdigit(expr[i])) {
            push(expr[i] - '0');  
        } else {  
            if (size() < 2) {
                printf("Invalid postfix expression\n");
                return 0;
            }
            int b = pop();  
            int a = pop(); 
            push(operation(expr[i], a, b));
        }
    }

    if (size() != 1) {
        printf("Invalid postfix expression\n");
        return 0;
    }

    return pop();  // final result
}

int main() {
    char postfix[SIZE];
    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    int result = evalPostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}