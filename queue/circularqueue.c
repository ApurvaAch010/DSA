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
    return (q->front == -1);
}

int isFull(struct Queue *q)
{
    return ((q->rear + 1) % SIZE == q->front);
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

    q->rear = (q->rear + 1) % SIZE;
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

    int element = q->items[q->front];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % SIZE;
    }

    printf("Dequeued %d\n", element);
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;

    while (1)
    {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % SIZE;
    }
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