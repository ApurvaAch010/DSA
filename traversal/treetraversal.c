#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
};

struct Node *getNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory alloation failed:\n");
        exit(1);
    }
    return newNode;
}

struct Queue
{
    struct Node *treeNode;
    struct Queue *next;
};

struct Queue *getQueue()
{
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
    if (newQueue == NULL)
    { 
        printf("Memory alloation failed:\n");
        exit(1);
    }
    return newQueue;
}

struct Queue *front = NULL;
struct Queue *rear = NULL;
void enqueue(struct Node *t)
{
    struct Queue *tree = getQueue();
    tree->treeNode = t;

    if (rear == NULL)
    {
        front = rear = tree;
        return;
    }
    rear->next = tree;
    rear = tree;
}

struct Node *dequeue()
{
    if (front == NULL)
    {
        return NULL;
    }
    struct Queue *temp = front;
    struct Node *t = temp->treeNode;

    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return t;
}

struct Node *insertTree(struct Node *root, int value)
{
    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    if (root == NULL)
    {
        return newNode;
    }
    front = rear = NULL;
    enqueue(root);
    while (front != NULL)
    {
        struct Node *temp = dequeue();
        if (temp->leftChild == NULL)
        {
            temp->leftChild = newNode;
            return root;
        }
        else
        {
            enqueue(temp->leftChild);
        }
        if (temp->rightChild == NULL)
        {
            temp->rightChild = newNode;
            return root;
        }
        else
        {
            enqueue(temp->rightChild);
        }
    }
    return root;
}

void inOrder(struct Node *root)
{
    if (!root)
        return;
    inOrder(root->leftChild);
    printf("%d ", root->data);
    inOrder(root->rightChild);
}

void postorder(struct Node *root)
{
    if (!root)
        return;
    postorder(root->leftChild);
    postorder(root->rightChild);
    printf("%d ", root->data);
}

void preorder(struct Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

int main()
{

    struct Node *root = NULL;
    int choice;
    char ch;
    do
    {
        
        printf("What do you want to do?\n 1. Insert a element in tree \n 2.InOrder-Traversal\n 3.PostOrder-traversal\n 4.PreOrder-traversal\n:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int x;
           
            printf("Enter the element:");
            scanf("%d",&x);
            root = insertTree(root, x);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            preorder(root);
            break;
        default:
           
            printf("Invalid choice \n");
        }
       
        printf("Do you want to continue?[Y/y]");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    printf("\n");
    return 0;
}
