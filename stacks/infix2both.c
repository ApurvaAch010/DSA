#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;
void push(char c) {
    if (top < 99)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int isEmpty() {
    return top == -1;
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


void reverseString(char str[]) {
    int i, j;
    char temp;
    int len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}


void reverseAndSwapParens(char infix[], char result[]) {
    int len = strlen(infix);
    int k = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (infix[i] == '(')
            result[k++] = ')';
        else if (infix[i] == ')')
            result[k++] = '(';
        else
            result[k++] = infix[i];
    }
    result[k] = '\0';
}


void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    top = -1;  

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[k++] = pop();
            pop();  
        }
        else {
            while (!isEmpty() && prec(peek()) >= prec(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    while (!isEmpty())
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int main() {
    char infix[100], postfix[100], prefix[100], temp[100];
    char ch = 'Y';
    int choice;

    while (ch == 'Y' || ch == 'y') {
        printf("Enter infix expression: ");
        scanf("%s", infix);

        printf("\n1. Prefix\n2. Postfix\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            infixToPostfix(infix, postfix);
            printf("Postfix: %s\n", postfix);
        }
        else if (choice == 1) {
            reverseAndSwapParens(infix, temp);
            infixToPostfix(temp, postfix);
            strcpy(prefix, postfix);
            reverseString(prefix);
            printf("Prefix: %s\n", prefix);
        }
        else {
            printf("Invalid choice\n");
        }

        printf("\nDo you want to check again (Y/N): ");
        scanf(" %c", &ch);
        printf("\n");
    }

    return 0;
}