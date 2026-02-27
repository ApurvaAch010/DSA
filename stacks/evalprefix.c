#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

/* Stack implementation */
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

int peek() {
    if (top >= 0)
        return stack[top];
    return 0;
}

int size() {
    return top + 1;
}

int isEmpty() {
    return top == -1;
}

/* Perform operation */
int operation(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:  return 0;
    }
}

/* Evaluate prefix expression */
int evalPrefix(char inf[]) {
    top = -1;   // reset stack
    int len = strlen(inf);

    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(inf[i])) {
            push(inf[i] - '0');   // convert char to int
        } else {
            if (size() < 2) {
                printf("Invalid prefix expression\n");
                return 0;
            }
            int a = pop();
            int b = pop();
            push(operation(inf[i], a, b));
        }
    }

    if (size() != 1) {
        printf("Invalid prefix expression\n");
        return 0;
    }

    return pop();
}

int main() {
    char prefix[SIZE];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    printf("Result = %d\n", evalPrefix(prefix));

    return 0;
}