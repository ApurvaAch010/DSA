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

struct Node *enqueue(struct Node *front, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL)
    {
        return newNode;
    }
    struct Node *temp = front;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return front;
}

struct Node *dequeue(struct Node *front)
{
    if (front == NULL)
    {
        cout << "Empty queue";
        return NULL;
    }
    struct Node *temp = front->next;
    cout << "Dequeued:" << front->data << endl;
    free(front);
    front = temp;
    return front;
}

struct Node *displayQueue(struct Node *front)
{
    if (front == NULL)
    {
        cout << "Empty queue";
        return NULL;
    }

    struct Node *temp=front;
    cout<<"Queue:";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return front;

}
int main()
{

    struct Node *front = NULL;
    char ch = 'Y';
    int choice;

    do
    {
        cout << "Choose \n 1.Enqueue\n 2.Dequeue\n 3.DisplayQueue\n" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter the value:";
            cin >> value;
            front = enqueue(front, value);

            break;
        case 2:
            front = dequeue(front);
            break;
        case 3:
            front = displayQueue(front);
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
