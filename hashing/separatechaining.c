#include <stdio.h>
#include<stdlib.h>
struct Chain
{
    int data;
    struct Chain *next;
};

struct Chain *getChain()
{
    struct Chain *newChain = (struct Chain *)malloc(sizeof(struct Chain));
    if (newChain == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    return newChain;
}
int main()
{
    int arr1[100],i,h, n, lno;
    struct Chain *hashtable[100];
    printf("Enter the number of values:");
    scanf("%d", &n);
    printf("Enter the number of locations:");
    scanf("%d", &lno);
    for (i = 0; i < n; i++)
    {
        printf("Enter value [%d]:", i + 1);
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < lno; i++)
        hashtable[i] = 0;
    for (i = 0; i < n; i++)
    {
       
        h = arr1[i] % lno;

       struct Chain *newChain = getChain();
        newChain->data = arr1[i];
        newChain->next = NULL;
        if (hashtable[h] == 0)
        {
            hashtable[h] = newChain;
        }
        else
        {
            newChain->next = hashtable[h];
            hashtable[h] = newChain;
        }
    }
    for (i = 0; i < lno; i++)
    {
        struct Chain *temp = hashtable[i];
        while (temp != NULL)
        {
            printf("Hashtable [%d]:%d\n",i,temp->data);
            temp = temp->next;
        }
    }
}