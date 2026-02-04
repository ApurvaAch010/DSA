//inorder post order pre order
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *leftChild;
    Node *rightChild;

    Node(int value)
    {
        this->value = value;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

Node *createTree(int n)
{
    Node *nine = new Node(9);
    Node *three = new Node(3);
    Node *five = new Node(5);
    five->rightChild = nine;
    Node *eight = new Node(8);
    eight->leftChild = three;
    Node *seven = new Node(7);
    seven->leftChild = five;
    seven->rightChild = eight;
    return seven;
}

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->leftChild);
    cout << root->value << " ";
    inOrder(root->rightChild);
}

// void postorder(Node *root)
// {
//     if (!root)
//         return;
//     postorder(root->leftChild);
//     postorder(root->rightChild);
//     cout << root->value << " ";
// }

// void preorder(Node *root)
// {
//     if (!root)
//         return;
//     cout << root->value << " ";
//     preorder(root->leftChild);
//     preorder(root->rightChild);
// }

int main()
{

    int arr[100],x;
    cout<<"Enter the number of elements";
    cin>>x;
    Node *root; 
    for(int i=0;i<x;i++){
        cout<<"Enter the "<<i+1<<"value for tree:";
        cin>>arr[i];
        root= createTree(arr[i]);
    }
    
    cout << "In-order traversal: ";
    inOrder(root); 
    // cout << "post-order traversla:";
    // postorder(root);
    // cout << "Pre order traversal: ";
    // preorder(root);

    cout << endl;
    return 0;
}
