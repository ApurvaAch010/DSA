#include <stdio.h>
#define N 100

int main()
{
    int n, arr[N], temp,i,j,minInd;
    printf("Enter the number of elements:");
    scanf("%d", &n);
   for (i = 0; i < n; i++)
    {
        printf("Enter arr[%d]:",i+1);
        scanf("%d",&arr[i]);
    
    }
    for (i = 0; i < n - 1; i++)
    {
        minInd = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
    }
    printf("Sorted array is: [");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("] \n");
    return 0;
}