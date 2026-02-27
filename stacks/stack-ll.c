#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *getNode() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return newNode;
}

struct Node *push(struct Node *top, int value) {
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = top;
    printf("Pushed: %d\n", value);
    return newNode;
}

struct Node *pop(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }

    struct Node *temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
    return top;
}

void topOfStack(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top of stack: %d\n", top->data);
}

void displayStack(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node *top = NULL;
    char ch = 'Y';
    int choice;

    do {
        printf("\nChoose:\n1. Push\n2. Pop\n3. Top of Stack\n4. Display Stack\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value: ");
                scanf("%d", &value);
                top = push(top, value);
                break;
            }
            case 2:
                top = pop(top);
                break;

            case 3:
                topOfStack(top);
                break;

            case 4:
                displayStack(top);
                break;

            default:
                printf("Invalid option\n");
        }

        printf("Do you want to continue? [Y/N]: ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');

    return 0;
}