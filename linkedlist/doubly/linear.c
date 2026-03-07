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

struct Node *IAL(struct Node *start, int value)
{

    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL)
    {
        newNode->prev = NULL;
        printf("Inserted at last: %d\n", value);
        return newNode;
    }

    struct Node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted at last: %d\n", value);
    return start;
}

struct Node *IAF(struct Node *start, int value)
{

    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = start;

    if (start != NULL)
        start->prev = newNode;

    printf("Inserted at beginning: %d\n", value);
    return newNode;
}

struct Node *IAKP(struct Node *start, int value, int pos)
{

    if (pos == 1)
        return IAF(start, value);

    struct Node *temp = start;
    for (int i = 1; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return start;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return start;
    }

    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
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

    struct Node *temp = start;
    start = start->next;

    if (start != NULL)
        start->prev = NULL;

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

    if (start->next == NULL)
    {
        printf("Deleted from last: %d\n", start->data);
        free(start);
        return NULL;
    }

    struct Node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    printf("Deleted from last: %d\n", temp->data);
    free(temp);
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
    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return start;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return start;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
    return start;
}

void display(struct Node *start)
{

    if (start == NULL)
    {
        printf("No node to display\n");
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
    struct Node *start = NULL;
    int choice, value, pos;

    do
    {
        printf("\n1.Insert at last\n2.Insert at beginning\n3.Insert at K position\n");
        printf("4.Delete from beginning\n5.Delete from last\n6.Delete from K position\n");
        printf("7.Display\n0.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value:");
            scanf("%d", &value);
            start = IAL(start, value);
            break;

        case 2:
            printf("Enter the value:");
            scanf("%d", &value);
            start = IAF(start, value);
            break;

        case 3:
            printf("Enter the position and the value:");
            scanf("%d %d", &pos, &value);
            start = IAKP(start, value, pos);
            break;

        case 4:
            start = dfb(start);
            break;

        case 5:
            start = dfl(start);
            break;

        case 6:
            printf("Position:");
            scanf("%d", &pos);
            start = dfkp(start, pos);
            break;

        case 7:
            display(start);
            break;
        }
    } while (choice != 0);

    return 0;
}