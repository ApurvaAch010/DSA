#include <stdio.h>
#include <stdlib.h>
struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *getNode()
{
    struct BstNode *newBstNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    if (newBstNode == NULL)
    {
        printf("Memory allcoation failed:\n");
        exit(1);
    }
    return newBstNode;
}

struct BstNode *find_min(struct BstNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL)
        return root;
    else
        return find_min(root->left);
}
struct BstNode *find_max(struct BstNode *root)
{
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    else
        return find_max(root->right);
}

struct BstNode *Insert(struct BstNode *root, int value)
{
    struct BstNode *newNode = getNode();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
    {
        printf("Inserted %d", value);
        return newNode;
    }
    else if (value <= root->data)
    {
        root->left = Insert(root->left, value);
    }
    else
    {
        root->right = Insert(root->right, value);
    }
    return root;
}

struct BstNode *delete(struct BstNode *root, int target)
{
    struct BstNode *temp;
    if (root == NULL)
    {
        printf("Empty tree \n");
        return NULL;
    }
    else if (target < root->data)
    {
        root->left = delete(root->left, target);
    }
    else if (target > root->data)
    {
        root->right = delete(root->right, target);
    }
    else if (root->left != NULL && root->right != NULL)
    {
        temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, root->data);
    }
    else
    {
        temp = root;
        if (root->left == NULL)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
        free(temp);
        return root;
    }
    return root;
}

int Searching(struct BstNode *root, int target)
{
    if (root == NULL)
        return 0;
    else if (root->data == target)
        return 1;
    else if (root->data >= target)
        return Searching(root->left, target);
    else
        return Searching(root->right, target);
}

void displaytree(struct BstNode *root)
{
    struct BstNode *temp = root;
    if (root == NULL)
        return;
    displaytree(root->left);
    printf("%d, ", root->data);
    displaytree(root->right);
}

int main()
{
    struct BstNode *root = NULL;

    int choice, x, target, result;
    do
    {
        printf("\n1. Insert\n 2. Deletion \n 3.Searching \n 4.Displaytree \n 5.FindMax \n 6.FindMin \n 0.Exit \n Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value to insert:");
            scanf("%d", &x);
            root = Insert(root, x);
            break;

        case 2:
            printf("Enter the target to delete from tree:");
            scanf("%d", &target);
            root = delete(root, target);
            break;
        case 3:
            printf("Enter the target to search:");
            scanf("%d", &target);
            if (Searching(root, target) == 1)
            {
                printf("Found %d in tree \n", target);
            }
            else
            {
                printf("Didnot find %d in tree\n", target);
            }
            break;
        case 4:
            displaytree(root);
            break;

        case 5:
            struct BstNode *maxNode = find_max(root);
            if (maxNode != NULL)
                printf("Maximum value in BST: %d\n", maxNode->data);
            else
                printf("Tree is empty\n");
            break;
        case 6:
            struct BstNode *minNode = find_min(root);
            if (minNode != NULL)
                printf("MinimumNode value in BST: %d\n", minNode->data);
            else
                printf("Tree is empty\n");
            break;
        case 0:
            printf("Exiting .... \n");
            break;
        default:
            printf("Invalid choice \n");
            break;
        }
    } while (choice != 0);
}