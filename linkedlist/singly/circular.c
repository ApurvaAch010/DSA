#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;

    struct Node *next;
};

struct Node *getNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // malloc returns a void*, which is a pointer that doesn’t know the type of data it points to.
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return newNode;
}

struct Node *insertAtLast(struct Node *heap, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = NULL;
    if (heap == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node *temp = heap;
    while (temp->next != heap)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = heap;

    return heap;
};

struct Node *insertatbeginning(struct Node *heap, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = heap;
    if (heap == NULL)
    {
        newNode->next = newNode;
        // heap=newNode;
        return newNode;
    }
    struct Node *temp = heap;
    while (temp->next != heap)
    {
        temp = temp->next;
    }
    newNode->next = heap;
    temp->next = newNode;
    heap = newNode;

    return newNode;
}

struct Node *atKposition(struct Node *heap, int pos, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = heap;

    if (heap == NULL)
    {
        newNode->next = newNode;
        // heap=newNode;
        return newNode;
    }
    struct Node *temp = heap;
    if (pos == 1)
    {

        while (temp->next != heap)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = heap;
        heap = newNode;
        return heap;
    }

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == heap)
        {
            printf("Invalid position\n");
            return heap;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return heap;
}

struct Node *dfb(struct Node *heap)
{
    if (heap == NULL)
    {
        printf("Empty listt\n");
        return NULL;
    }
    if (heap->next == heap)
    {
        free(heap);
        return NULL;
    }
    struct Node *temp = heap;
    while (temp->next != heap)
    {
        temp = temp->next;
    }
    struct Node *oldHead = heap;
    temp->next = heap->next;
    heap = heap->next;
    free(oldHead);
    return heap;
}

struct Node *dfe(struct Node *heap)
{
    if (heap == NULL)
    {
        printf("EMPTY linkedlist");
        return NULL;
    }
    if (heap->next == heap)
    {
        free(heap);
        return NULL;
    }
    struct Node *temp = heap;
    while (temp->next->next != heap)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = heap;
    return heap;
}

struct Node *dfkp(struct Node *heap, int pos)
{
    if (heap == NULL)
    {
        printf("EMPTY linkedlist");
        return NULL;
    }
    if (heap->next == heap)
    {
        free(heap);
        return NULL;
    }
    if (pos == 1)
    {
        struct Node *temp = heap;
        while (temp->next != heap)
        {
            temp = temp->next;
        }

        temp->next = heap->next;
        struct Node *newHead = heap->next;
        free(heap);
        return newHead;
    }
    struct Node *temp = heap;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp->next == heap)
        {
            printf("Invalid position\n");
            return NULL;
        }
    }
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return heap;
}
void display(struct Node *heap)
{
    if (heap == NULL)
    {
        printf("EMPTY linkedlist");
        exit(1);
    }

    struct Node *temp = heap;
    do
    {

        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != heap);
    printf("\n");
}
int main()
{
    struct Node *heap = NULL;
    int choice, value, pos;

    do
    {

        printf("CHOICES\n 1.Insert at last \n 2. Insert at beginning\n 3. Insert at K position\n 4. Delete from beginning\n 5. Delete from end\n 6. Delete from K position\n 7. Display list\n \n Enter choice:");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter value:");
            scanf("%d", &value);
            heap = insertAtLast(heap, value);
            break;

        case 2:
            printf("Enter value:");
            scanf("%d", &value);
            heap = insertatbeginning(heap, value);
            break;

        case 3:
            printf("Enter position:");
            scanf("%d", &pos);
            printf("Enter value:");
            scanf("%d", &value);
            heap = atKposition(heap, pos, value);
            break;

        case 4:
            heap = dfb(heap);
            break;

        case 5:
            heap = dfe(heap);
            break;

        case 6:
            printf("Enter position:");
            scanf("%d", &pos);
            heap = dfkp(heap, pos);
            break;

        case 7:
            display(heap);
            break;

        default:

            printf("Invalid choice \n");
            break;
        }
        printf("Enter 1 to continue 0 to discontinue:");
        scanf("%d",&choice);

    } while (choice != 0);

    return 0;
}
