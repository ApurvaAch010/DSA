#include <stdio.h>
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
    int arr1[100], n, lno;
    struct Chain *hashtable[100];
    printf("Enter the number of values:");
    scanf("%d", &n);
    printf("Enter the number of locations:");
    scanf("%d", &lno);
    for (int i = 0; i < n; i++)
    {
        printf("Enter value [%d]:", i + 1);
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < lno; i++)
        hashtable[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int h = arr1[i] % lno;

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
    for (int i = 0; i < lno; i++)
    {
        struct Chain *temp = hashtable[i];
        while (temp != NULL)
        {
            printf("Hashtable [%d]:%d\n",i,temp->data);
            temp = temp->next;
        }
    }
}