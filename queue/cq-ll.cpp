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

struct Node *enqueue(struct Node *rear, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    newNode->next=rear->next;
    rear->next=newNode;
    rear=newNode;
    return rear;
}

struct Node *dequeue(struct Node *rear)
{
    if (rear == NULL)
    {
        cout << "Empty queue";
        return NULL;
    }
    struct Node *front=rear->next;
    if(front==rear){
        cout<<"Deqeued"<<front->data<<" ";
        free(front);
        return NULL;
    }
    cout<<"Dequeued"<<front->data<<" ";
    rear->next=front->next;
    free(front);
    return rear;
}

struct Node *displayQueue(struct Node *rear)
{
    
    if (rear == NULL)
    {
        cout << "Empty queue";
        return NULL;
    }
    struct Node *temp=rear->next;
    cout<<"Queue:";
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=rear->next);
    cout<<endl;
    return rear;

}
int main()
{

    struct Node *rear = NULL;
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
            rear = enqueue(rear, value);

            break;
        case 2:
            rear = dequeue(rear);
            break;
        case 3:
            rear = displayQueue(rear);
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
