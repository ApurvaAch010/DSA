#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
private:
    int items[SIZE], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            int element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
            cout << "Dequeued " << element << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (true) {
                cout << items[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    char ch;
    int value;

    do {
        cout << "\nChoose operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case '1':
            cout << "Enter element: ";
            cin >> value;
            q.enqueue(value);
            break;
        case '2':
            q.dequeue();
            break;
        case '3':
            q.display();
            break;
        case '4':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid input\n";
        }
    } while (ch != '4');

    return 0;
}
