#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    int freq;
    struct Node *left,*right;
};

struct Node* createNode(char data,int freq){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->freq=freq;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void swap(struct Node** a, struct Node** b){
    struct Node* temp=*a;
    *a=*b;
    *b=temp;
}

void sort(struct Node* arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]->freq > arr[j+1]->freq){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

struct Node* buildHuffman(struct Node* arr[],int n){
    while(n>1){
        sort(arr,n);

        struct Node* left=arr[0];
        struct Node* right=arr[1];

        struct Node* newNode=createNode('$',left->freq + right->freq);
        newNode->left=left;
        newNode->right=right;

        arr[0]=newNode;
        arr[1]=arr[n-1];
        n--;
    }

    return arr[0];
}

void printCodes(struct Node* root,int arr[],int top){
    if(root->left){
        arr[top]=0;
        printCodes(root->left,arr,top+1);
    }

    if(root->right){
        arr[top]=1;
        printCodes(root->right,arr,top+1);
    }

    if(!root->left && !root->right){
        printf("%c : ",root->data);
        for(int i=0;i<top;i++)
            printf("%d",arr[i]);
        printf("\n");
    }
}

int main(){
    int n;

    printf("Enter number of characters: ");
    scanf("%d",&n);

    char ch[n];
    int freq[n];

    for(int i=0;i<n;i++){
        printf("Enter character and frequency: ");
        scanf(" %c %d",&ch[i],&freq[i]);
    }

    struct Node* arr[n];

    for(int i=0;i<n;i++){
        arr[i]=createNode(ch[i],freq[i]);
    }

    struct Node* root=buildHuffman(arr,n);

    int code[100];
    printf("\nHuffman Codes:\n");
    printCodes(root,code,0);

    return 0;
}