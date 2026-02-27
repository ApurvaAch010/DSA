#include <stdio.h>
#define SIZE 5

struct Queue
{
    int items[SIZE];
    int front;
    int rear;
};

int isEmpty(struct Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

int isFull(struct Queue *q)
{
    return (q->rear == SIZE - 1);
}

void enqueue(struct Queue *q, int element)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->items[q->rear] = element;
    printf("Inserted %d\n", element);
}

void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Dequeued %d\n", q->items[q->front]);
    q->front++;
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main()
{
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    char ch;
    int value;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter choice: ");
        scanf(" %c", &ch);

        switch (ch)
        {
        case '1':
            printf("Enter element: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;

        case '2':
            dequeue(&q);
            break;

        case '3':
            display(&q);
            break;

        case '4':
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid input\n");
        }

    } while (ch != '4');

    return 0;
}