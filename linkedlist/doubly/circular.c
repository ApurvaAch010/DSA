#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *getNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }
    return newNode;
}


struct Node *IAF(struct Node *start, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;

    if (start == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        printf("Inserted at beginning: %d\n", value);
        return newNode;
    }

    struct Node *last = start->prev;

    newNode->next = start;
    newNode->prev = last;
    start->prev = newNode;
    last->next = newNode;

    printf("Inserted at beginning: %d\n", value);
    return newNode;
}


struct Node *IAL(struct Node *start, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;

    if (start == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        printf("Inserted at last: %d\n", value);
        return newNode;
    }

    struct Node *last = start->prev;

    newNode->next = start;
    newNode->prev = last;
    last->next = newNode;
    start->prev = newNode;

    printf("Inserted at last: %d\n", value);
    return start;
}


struct Node *IAKP(struct Node *start, int pos, int value)
{
    if (pos == 1)
        return IAF(start, value);

    if (start == NULL)
    {
        printf("Invalid position\n");
        return NULL;
    }

    struct Node *temp = start;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == start)
        {
            printf("Invalid position\n");
            return start;
        }
    }

    struct Node *newNode = getNode();
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printf("Inserted %d at position %d\n", value, pos);
    return start;
}


struct Node *dfb(struct Node *start)
{
    if (start == NULL)
    {
        printf("No node to delete\n");
        return NULL;
    }

    struct Node *last = start->prev;

    if (start == last)
    {
        printf("Deleted from beginning: %d\n", start->data);
        free(start);
        return NULL;
    }

    struct Node *temp = start;
    last->next = start->next;
    start->next->prev = last;
    start = start->next;

    printf("Deleted from beginning: %d\n", temp->data);
    free(temp);
    return start;
}

struct Node *dfl(struct Node *start)
{
    if (start == NULL)
    {
        printf("No node to delete\n");
        return NULL;
    }

    struct Node *last = start->prev;

    if (start == last)
    {
        printf("Deleted from last: %d\n", start->data);
        free(start);
        return NULL;
    }

    last->prev->next = start;
    start->prev = last->prev;

    printf("Deleted from last: %d\n", last->data);
    free(last);
    return start;
}

struct Node *dfkp(struct Node *start, int pos)
{
    if (start == NULL)
    {
        printf("No node to delete\n");
        return NULL;
    }

    if (pos == 1)
        return dfb(start);

    struct Node *temp = start;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp->next == start)
        {
            printf("Invalid position\n");
            return start;
        }
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;

    printf("Deleted %d from position %d\n", nodeToDelete->data, pos);
    free(nodeToDelete);
    return start;
}

void display(struct Node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = start;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("(back to start)\n");
}

int main()
{
    struct Node *start = NULL;
    int choice, value, pos;

    do
    {
        printf("\n1. Insert at last\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at K position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from last\n");
        printf("6. Delete from K position\n");
        printf("7. Display list\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            start = IAL(start, value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            start = IAF(start, value);
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &value);
            start = IAKP(start, pos, value);
            break;

        case 4:
            start = dfb(start);
            break;

        case 5:
            start = dfl(start);
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            start = dfkp(start, pos);
            break;

        case 7:
            display(start);
            break;

        case 0:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}