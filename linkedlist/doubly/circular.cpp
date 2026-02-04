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
        cout << "Error allocating memory";
        exit(1);
    }
    return newNode;
}
// cases:when null,when there are other nodes
struct Node *IAF(struct Node *start, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (start == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    struct Node *last = start->prev;

    start->prev = newNode;
    newNode->next = start;
    newNode->prev = last;
    last->next = newNode;
    start = newNode;
    return start;
}

// case:no node,othernodes
struct Node *IAL(struct Node *start, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (start == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        return newNode;
    }
    struct Node *last = start->prev;
    newNode->next = start;
    newNode->prev = last;
    start->prev = newNode;
    last->next = newNode;
    return start;
}

// case: no node,other nodes,node at first position
struct Node *IAKP(struct Node *start, int pos, int value)
{

    if (pos == 1)
    {
        return IAF(start, value);
    }
    struct Node *newNode = getNode();
    newNode->data = value;
    if (start == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    struct Node *temp = start;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == start)
        {
            cout << "Invalid position\n";
            return start;
        }
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return start;
}

// case:no node,only one node,few nodes
struct Node *dfb(struct Node *start)
{
    if (start == NULL)
    {
        cout << "No node to delete";
        return NULL;
    }
    struct Node *last = start->prev;
    if (last == start)
    {
        delete (start);
        return NULL;
    }
    struct Node *oldNode = start;
    last->next = oldNode->next;
    oldNode->next->prev = last;
    start = last->next;
    delete oldNode;
    return start;
}
// case:no node,only one node,fewnodes;
struct Node *dfl(struct Node *start)
{
    if (start == NULL)
    {
        cout << "No node to delete";
        return NULL;
    }
    struct Node *last = start->prev;
    if (last == start)
    {
        delete start;
        return NULL;
    }

    start->prev = last->prev;
    last->prev->next = start;
    delete last;
    return start;
}

// case:no node,only one node|pos=1,node in between
struct Node *dfkp(struct Node *start, int pos)
{
    if (pos == 1)
    {
        return dfb(start);
    }
    if (start == NULL)
    {
        cout << "No node to delete";
        return NULL;
    }
    struct Node *temp = start;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp->next == start)
        {
            cout << "Invalid position";
            return start;
        }
    }
    struct Node *nodetoDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;

    delete nodetoDelete;
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
}
