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

int evalPrefix(char expr[]) {
    top = -1;
    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            if (size() < 2) {
                printf("Invalid prefix expression\n");
                return 0;
            }
            int a = pop();
            int b = pop();
            push(operation(expr[i], a, b));
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
    scanf("%s", prefix);
    printf("%d\n", evalPrefix(prefix));
    return 0;
}