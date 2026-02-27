#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;

struct Node *getNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return newNode;
}

void addNodeatfirst(int dat)
{
    struct Node *newNode = getNode();
    newNode->data = dat;
    newNode->next = start;
    start = newNode;
}

void addNodeatlast(int dat)
{
    struct Node *newNode = getNode();
    newNode->data = dat;
    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
        return;
    }

    struct Node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void inbetween(int dat, int position)
{
    if (position == 1)
    {
        addNodeatfirst(dat);
        return;
    }

    struct Node *newNode = getNode();
    newNode->data = dat;

    struct Node *temp = start;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void dfl()
{
    if (start == NULL)
    {
        printf("No linked list left\n");
        return;
    }

    struct Node *temp = start;
    start = start->next;
    free(temp);
}

void dfb()
{
    if (start == NULL)
    {
        printf("No linked list left\n");
        return;
    }

    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }

    struct Node *temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void dfkp(int pos)
{
    if (start == NULL)
    {
        printf("No linked list left\n");
        return;
    }

    if (pos == 1)
    {
        dfl();
        return;
    }

    struct Node *temp = start;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void display()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = start;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    char ch = 'Y';
    int x, y, pos;

    while (ch == 'Y' || ch == 'y')
    {
        printf("\nChoices");
        printf("\n1. Add at first");
        printf("\n2. Add at last");
        printf("\n3. Add in between");
        printf("\n4. Delete from first");
        printf("\n5. Delete from last");
        printf("\n6. Delete from k position");
        printf("\n7. Display\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &y);
            addNodeatfirst(y);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &y);
            addNodeatlast(y);
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &y);
            inbetween(y, pos);
            break;

        case 4:
            dfl();
            break;

        case 5:
            dfb();
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            dfkp(pos);
            break;

        case 7:
            display();
            break;

        default:
            printf("Invalid choice\n");
        }

        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &ch);
    }

    return 0;
}