#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *values;
    int front, rear, size;
};

void initQueue(struct Queue *q, int size)
{
    q->size = size;
    q->values = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

int isFull(struct Queue *q)
{
    return (q->rear == q->size - 1);
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->values[++q->rear] = value;
}

void dequeue(struct Queue *q, char ch)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    int index = q->front;

    if (ch == '1')
    {
        for (int i = q->front + 1; i <= q->rear; i++)
            if (q->values[i] < q->values[index])
                index = i;
    }
    else if (ch == '2')
    {
        for (int i = q->front + 1; i <= q->rear; i++)
            if (q->values[i] > q->values[index])
                index = i;
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    printf("Deleted element: %d\n", q->values[index]);

    for (int i = index; i < q->rear; i++)
        q->values[i] = q->values[i + 1];

    q->rear--;
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->values[i]);
    printf("\n");
}

int main()
{
    struct Queue q;
    int size, value;
    char ch, choice, con = 'y';

    printf("Enter size of queue: ");
    scanf("%d", &size);

    initQueue(&q, size);

    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\nEnter choice: ");
        scanf(" %c", &ch);

        switch (ch)
        {
        case '1':
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;

        case '2':
            printf("1. Ascending deletion\n2. Descending deletion\nEnter choice: ");
            scanf(" %c", &choice);
            dequeue(&q, choice);
            break;

        case '3':
            display(&q);
            break;

        default:
            printf("Invalid option\n");
        }

        printf("Do you want to continue (y/n): ");
        scanf(" %c", &con);

    } while (con == 'y' || con == 'Y');

    free(q.values);
    return 0;
}