#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *getNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); /// malloc returns a void*, which is a pointer that doesn’t know the type of data it points to.
    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    return newNode;
}

struct Node *InsertAtLast(struct Node *heap, int value)
{

    struct Node *newNode = getNode();
    newNode->data = value;
    newNode->next = NULL;

    if (heap == NULL)
    {
        return newNode;
    }
    struct Node *temp = heap;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return heap;
}
struct Node *InsertAtFirst(struct Node *heap, int value)
{

    struct Node *newNode = getNode();
    newNode->data=value;
    newNode->next = heap;
}
struct Node *InsertInbetween(struct Node *heap, int value, int position)
{

    struct Node *newNode = getNode();

    if (position == 1)
    {
        newNode->data=value;
        newNode->next = heap;
        return;
    }
    struct Node *temp=heap;
    for(int i=1;i<position-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid position");
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

int main()
{
    struct Node *head = NULL;

    head = InsertAtLast(head, 10);
    head = InsertAtLast(head, 20);
    head = InsertAtLast(head, 30);

    // PrintList(head);

    // free memory
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
