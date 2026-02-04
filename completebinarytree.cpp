#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left =nullptr;
         right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Insert left child first
        if (curr->left == nullptr) {
            curr->left = new Node(value);
            break;
        } else {
            q.push(curr->left);
        }

        // Then insert right child
        if (curr->right == nullptr) {
            curr->right = new Node(value);
            break;
        } else {
            q.push(curr->right);
        }
    }

    return root;
}


int main() {
    Node* root = nullptr;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    // levelOrder(root); // Output: 1 2 3 4 5 6
    return 0;
}
