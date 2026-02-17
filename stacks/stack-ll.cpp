#include <iostream>
using namespace std;
struct Node
{
    int data;
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

struct Node *push(struct Node *top, int value)
{
    struct Node *newNode = getNode();

    newNode->data = value;
    newNode->next = top;
    cout << "Pushed:" << value;
    return newNode;
}

struct Node *pop(struct Node *top)
{
    if (top == NULL)
    {
        cout << "Stack is empty";
        return NULL;
    }

    struct Node *temp = top;
    cout << "Popped:" << temp->data;
    top = top->next;
    free(temp);

    return top;
}

struct Node *topOfStack(struct Node *top)
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return NULL;
    }
    cout << "The top of the stack is" << top->data;
    return top;
}

struct Node *displayStack(struct Node *top)
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return NULL;
    }
    struct Node *temp = top;
    cout<<"STACK:";
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
    return top;
}

int main()
{

    struct Node *top = NULL;
    char ch = 'Y';
    int choice;

    do
    {
        cout << "Choose \n 1.Push\n 2.Pop\n 3.topOfStack\n 4.DisplayStack" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter the value:";
            cin >> value;
            top = push(top, value);

            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            top = topOfStack(top);
            break;
        case 4:
            top = displayStack(top);
            break;
        default:
            cout << "Invalid Input";
            break;
        }
        cout<<"\n Do you want to continue?[Y/N]:";
        cin>>ch;

    } while (ch == 'Y' || ch == 'y');
    return 0;
}
