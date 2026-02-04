#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *heap;

public:
    LinkedList()
    {
        heap = nullptr;
    }

    void addNodeatfirst(int dat)
    {
        Node *newNode = new Node(dat);
        newNode->next = heap;
        heap = newNode;
    }

    void inbetween(int dat, int position)
    {
        Node *newNode = new Node(dat);

        if (position == 1)
        {
            newNode->next = heap;
            heap = newNode;
            return;
        }
        Node *temp = heap;
        for (int i = 1; i < position - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Invalid position\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void addNodeatlast(int dat)
    {
        Node *newNode = new Node(dat);
        if (heap == nullptr)
        {
            heap = newNode;
            return;
        }
        Node *temp = heap;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void dfl()
    {
        if (heap == nullptr)
        {
            cout << "No linked list left";
            return;
        }
        if (heap->next == nullptr)
        {
            delete heap;
            heap = nullptr;
            return;
        }
        Node *temp = heap;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void dfb()
    {
        if (heap == nullptr)
        {
            cout << "No linked list left\n";
            return;
        }

        Node *temp = heap;
        heap = heap->next;
        delete temp;
    }

    void dfkp(int pos)
    {
        if (heap == nullptr)
        {
            cout << "No linked list left";
            return;
        }
        if (pos == 1)
        {
            Node *temp = heap;
            heap = heap->next;
            delete temp;
            return;
        }
        Node *temp = heap;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp->next = nullptr)
            {
                cout << "Invalid position";
                return;
            }
        }
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void display()
    {
        Node *temp = heap;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null \n";
    }
};
int main()
{
    LinkedList l;

    char ch = 'Y';
    int x, y;
    while (ch == 'Y' || ch == 'y')
    {
        cout << "Enter what you want to do: \n 1. Add from first \n 2. Add from last\n 3. Add in between\n  4. Delete from first \n 5. delete from last\n 6. delete from k position\n 7.display" << endl;
        cin >> x;

        switch (x)
        {
        case (1):
            cout << "\nEnter the value you want to add:";
            cin >> y;
            l.addNodeatfirst(y);
            break;
        case (2):
            cout << "\nEnter the value you want to add:";
            cin >> y;
            l.addNodeatlast(y);
            break;
        case (3):
            int pos;
            cout << "Enter the position you want to insert in:";
            cin >> pos;
            cout << "\nEnter the value you want to add:";
            cin >> y;
            l.inbetween(y, pos);
            break;
        case (4):
            l.dfl();
            break;
        case (5):
            l.dfb();
            break;
        case (6):
            int pos;
            cout << "Enter the postion you want to delete in:";
            cin >> pos;
            l.dfkp(pos);
            break;
        case (7):
            l.display();
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "Do you wanna continue(y/Y||n/N)";
        cin >> ch;
    }

    return 0;
}
