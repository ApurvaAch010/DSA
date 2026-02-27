#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *getNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        cout << "Error alloacting memory";
        exit(1);
    }
    return newNode;
}

// case: no linked list, and other linked list
struct Node *IAL(struct Node *start, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return start;
}

struct Node *IAF(struct Node *start, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = start;

    if (start != NULL)
    {
        start->prev = newNode;
    }

    return newNode;
}

struct Node *IAKP(struct Node *start, int value, int pos)
{
    if (pos == 1)
    {
        return IAF(start, value);
    }
    struct Node *newNode = getNode();
    newNode->data = value;
    struct Node *temp = start;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp->next == start)
        {
            cout << "Invalid choice";
            return start;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    temp->next->prev = newNode;
    newNode->prev = temp;
    return start;
}

struct Node *dfb(struct Node *start)
{
    if (start == NULL)
        return NULL;

    struct Node *nodetoDelete = start;
    start = start->next;

    if (start != NULL)
    {
        start->prev = NULL;
    }

    delete nodetoDelete;
    return start;
}

struct Node *dfl(struct Node *start)
{
    if (start == NULL)
        return NULL;

    if (start->next == NULL)
    {
        delete start;
        return NULL;
    }

    struct Node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;

    return start;
}

struct Node *dfkp(struct Node *start, int pos)
{
    if (start == NULL)
        return NULL;

    if (start->next == NULL)
    {
        delete start;
        return NULL;
    }
    struct Node *temp = start;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "INVALID POSITION";
            return start;
        }
    }
    struct Node *nodetodelete = temp->next;
    temp->next = nodetodelete->next;
    nodetodelete->next->prev = temp;
    return start;
}
struct Node *display(struct Node *start)
{
    if (start == NULL)
    {
        cout << "No node to display";
        return NULL;
    }
    struct Node *temp = start;
    do
    {

        cout << temp->data << "-> \t";
        temp = temp->next;
    } while (temp != start);
    return start;
}

int main()
{
    struct Node *start = NULL;
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
            start = IAL(start, value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            start = IAF(start, value);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            start = IAKP(start, pos, value);
            break;

        case 4:
            start = dfb(start);
            break;

        case 5:
            start = dfl(start);
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            start = dfkp(start, pos);
            break;

        case 7:
            display(start);
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