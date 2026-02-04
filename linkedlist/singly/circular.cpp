#include <iostream>
using namespace std;
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
        cout << "Memory allocation failed" << endl;
        exit(1);
    }
    return newNode;
}

struct Node *insertAtLast(struct Node *heap, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = nullptr;
    if (heap == nullptr)
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
    if (heap == nullptr)
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
            cout << "Inavlid position";
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
        cout << "NOTHING IS LEFT TO DELETE FROM";
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
        cout << "NOTHING IS LEFT TO DELETE FROM";
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
        cout << "NOTHING IS LEFT TO DELETE FROM";
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
            cout << "Invalid position";
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
        cout << "List is empty\n";
        return;
    }

    struct Node *temp = heap;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != heap);

    cout << endl;
}
int main()
{
    struct Node *heap = NULL;
    int choice, value, pos;

    do
    {
        cout << "1. Insert at last\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at K position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from K position\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            heap = insertAtLast(heap, value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            heap = insertatbeginning(heap, value);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            heap = atKposition(heap, pos, value);
            break;

        case 4:
            heap = dfb(heap);
            break;

        case 5:
            heap = dfe(heap);
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            heap = dfkp(heap, pos);
            break;

        case 7:
            display(heap);
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
