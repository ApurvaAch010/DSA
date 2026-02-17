#include <iostream>
#include <stdlib.h>
using namespace std;

struct Queue{
    int *values;
    int front, rear, size;
};

void initQueue(Queue &q, int size){
    q.size = size;
    q.values = new int[size];
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(Queue &q){
    return (q.front == -1 || q.front > q.rear);
}

bool isFull(Queue &q)
{
    return (q.rear == q.size - 1);
}

void enqueue(Queue &q, int value)
{
    if (isFull(q))
    {
        cout << "Queue is full\n";
        return;
    }
    if (q.front == -1)
        q.front = 0;
    q.values[++q.rear] = value;
}

void dequeue(Queue &q, char ch)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty\n";
        return;
    }

    int index = q.front;

    if (ch == '1')
    {
        for (int i = q.front + 1; i <= q.rear; i++)
            if (q.values[i] < q.values[index])
                index = i;
    }
    else if (ch == '2')
    {
        for (int i = q.front + 1; i <= q.rear; i++)
            if (q.values[i] > q.values[index])
                index = i;
    }
    else
    {
        cout << "Invalid choice\n";
        return;
    }

    cout << "Deleted: " << q.values[index] << endl;

    for (int i = index; i < q.rear; i++)
        q.values[i] = q.values[i + 1];

    q.rear--;
}

void display(Queue &q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty\n";
        return;
    }

    for (int i = q.front; i <= q.rear; i++)
        cout << q.values[i] << " ";
    cout << endl;
}

int main()
{
    Queue q;
    int size, value;
    char ch, choice;

    cin >> size;
    initQueue(q, size);

    do
    {
        cin >> ch;
        switch (ch)
        {
        case '1':
            cin >> value;
            enqueue(q, value);
            break;
        case '2':
            cin >> choice;
            dequeue(q, choice);
            break;
        case '3':
            display(q);
            break;
        }
    } while (ch != '4');

    delete[] q.values;
    return 0;
}
