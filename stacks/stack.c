#include <stdio.h>
#define SIZE 5

int sp = -1;
int arr[SIZE];

void push(int x) {
    if (sp == SIZE - 1) {
        printf("STACK OVERFLOW\n");
        return;
    }
    arr[++sp] = x;
    printf("Pushed: %d\n", x);
}

void pop() {
    if (sp == -1) {
        printf("STACK UNDERFLOW\n");
        return;
    }
    printf("Popped element: %d\n", arr[sp--]);
}

void topelement() {
    if (sp == -1) {
        printf("STACK UNDERFLOW\n");
        return;
    }
    printf("Top of stack: %d\n", arr[sp]);
}

int main() {
    int ch;
    char choice;

    do {
        printf("\nCHOOSE:\n1. PUSH\n2. POP\n3. Top Element\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int a;
                printf("Enter the element: ");
                scanf("%d", &a);
                push(a);
                break;
            }
            case 2:
                pop();
                break;

            case 3:
                topelement();
                break;

            default:
                printf("Invalid option\n");
        }

        printf("Do you want to continue [Y/N]: ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    return 0;
}