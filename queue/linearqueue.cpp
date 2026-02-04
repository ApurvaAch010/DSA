#include <iostream>
#define SIZE 5
using namespace std;
class Queue
{
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        return false;
    }
    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "The queue is full";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            items[rear] = element;

            cout << "Inserted" << element << endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty";
        }
        else
        {

            cout << "Dequeued" << items[front];
            front++;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << items[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    char ch;
    int value;
    do
    {
        cout << "Choose what to perform in queue" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Deuqueue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice:";
        cin >> ch;

        switch (ch)
        {
        case '1':
            cout << "Enter element:";
            cin >> value;
            q.enqueue(value);
            break;
        case '2':
            q.dequeue();
            break;
        case '3':
            q.display();
            break;
        default:
            cout<<"Invalid input";
        }
    }while(ch!='4');
    return 0;
}