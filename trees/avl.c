#include<stdio.h>

#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a,int b){
    return a>b?a:b;
}

int getHeight(struct Node *n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

struct Node *createNode(int value){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    return newNode;
}

int getBalanceFct(struct Node *n){
    if(n==NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* rightRotate(struct Node *root){
    struct Node *temp1=root->left;
    struct Node *temp2=temp1->right;

    temp1->right=root;
    root->left=temp2;


    root->height=max(getHeight(root->right),getHeight(root->left))+1;
    temp1->height=max(getHeight(temp1->right),getHeight(temp1->left))+1;

    return temp1;

}
struct Node* leftRotate(struct Node *root){
    struct Node *temp1=root->right;
    struct Node *temp2=temp1->left;

    temp1->left=root;
    root->right=temp2;


    temp1->height=max(getHeight(temp1->right),getHeight(temp1->left))+1;
    root->height=max(getHeight(root->right),getHeight(root->left))+1;

    return temp1;

}

struct Node *Insert(struct Node *root,int value){
     
    if (root == NULL)
    {
        
        return createNode(value);
    }
    else if (value <= root->data)
    {
        root->left = Insert(root->left, value);
    }
    else
    {
        root->right = Insert(root->right, value);
    }
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int bf=getBalanceFct(root);

    if(bf>1 && value<root->left->data){
        return rightRotate(root);
    }
    if(bf<-1 && value>root->right->data){
        return leftRotate(root);
    }
    if(bf>1 && value>root->left->data){
        root->left=leftRotate(root->left);
       return rightRotate(root);
    }
    if(bf<-1 && value>root->right->data){
       root->right=rightRotate(root->right);
       return leftRotate(root);
    }
    return root;
}
struct Node* findMin(struct Node* root){
    struct Node* current = root;
    while(current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key){
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else{
       
        if(root->left == NULL || root->right == NULL){
            struct Node* temp = root->left ? root->left : root->right;

            if(temp == NULL){
            
                temp = root;
                root = NULL;
            } else{
               
                *root = *temp;
            }
            free(temp);
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if(root == NULL) 
        return root;

    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int bf = getBalanceFct(root);

    
    if(bf > 1 && getBalanceFct(root->left) >= 0)
        return rightRotate(root);

    
    if(bf > 1 && getBalanceFct(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

   
    if(bf < -1 && getBalanceFct(root->right) <= 0)
        return leftRotate(root);

   
    if(bf < -1 && getBalanceFct(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void displaytree(struct Node *root)
{
    struct Node *temp = root;
    if (root == NULL)
        return;
    displaytree(root->left);
    printf("%d, ",root->data);
    displaytree(root->right);
}

int main(){
    struct Node *root=NULL;
    int choice,x;
    do
    {
        printf("\nEnter yout choice\n1.Insert\n2.display\n3.Delete\n0.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to store:");
            scanf("%d",&x);
            root=Insert(root,x);
            break;
        case 2:
            displaytree(root);
            break;
        case 3:
            printf("Enter the data you want to delete:");
            scanf("%d",&x);
            root=deleteNode(root,x);
            break;
        case 0:
            printf("Exiting...\n");
            return 0;
        default:
            break;
        }
    } while (choice!=0);
    
    return 0;
}