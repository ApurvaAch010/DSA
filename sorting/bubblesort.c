#include <stdio.h>
#define N 100
int main()
{
    int arr[N], n, temp;

    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",arr[i]);
    
    };
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array is: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("] \n");
    return 0;
}