#include <stdio.h>
#define N 100
int main()
{
    int arr[N], n, temp,j,i;

    printf("Enter the value of n:");
    scanf("%d",&n);
    
    for (i = 0; i < n; i++)
    {
        printf("Enter arr[%d]:",i+1);
        scanf("%d",&arr[i]);
    
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array is: [");
    for (i = 0; i < n; i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("] \n");
    return 0;
}