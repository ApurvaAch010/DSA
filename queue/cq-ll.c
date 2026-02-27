#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
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

struct Node *enqueue(struct Node *rear, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;

    if (rear == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = rear->next;
    rear->next = newNode;
    return newNode;
}

struct Node *dequeue(struct Node *rear)
{
    if (rear == NULL)
    {
        printf("Empty queue\n");
        return NULL;
    }

    struct Node *front = rear->next;

    if (front == rear)
    {
        printf("Dequeued %d\n", front->data);
        free(front);
        return NULL;
    }

    printf("Dequeued %d\n", front->data);
    rear->next = front->next;
    free(front);
    return rear;
}

struct Node *displayQueue(struct Node *rear)
{
    if (rear == NULL)
    {
        printf("Empty queue\n");
        return rear;
    }

    struct Node *temp = rear->next;
    printf("Queue: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
    return rear;
}

int main()
{
    struct Node *rear = NULL;
    char ch = 'Y';
    int choice, value;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.DisplayQueue\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            rear = enqueue(rear, value);
            break;

        case 2:
            rear = dequeue(rear);
            break;

        case 3:
            rear = displayQueue(rear);
            break;

        default:
            printf("Invalid choice\n");
        }

        printf("Do you want to continue? [Y/N]: ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');

    return 0;
}