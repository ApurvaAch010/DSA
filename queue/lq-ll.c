#include<stdio.h>
#include<stdlib.h>

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

struct Node *enqueue(struct Node *front, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
        return newNode;

    struct Node *temp = front;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return front;
}

struct Node *dequeue(struct Node *front)
{
    if (front == NULL)
    {
        printf("Empty queue\n");
        return NULL;
    }

    struct Node *temp = front->next;
    printf("Dequeued %d\n", front->data);
    free(front);
    return temp;
}

struct Node *displayQueue(struct Node *front)
{
    if (front == NULL)
    {
        printf("Empty queue\n");
        return front;
    }

    struct Node *temp = front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return front;
}

int main()
{
    struct Node *front = NULL;
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
            front = enqueue(front, value);
            break;

        case 2:
            front = dequeue(front);
            break;

        case 3:
            front = displayQueue(front);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }

        printf("Do you want to continue? [Y/N]: ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');

    return 0;
}