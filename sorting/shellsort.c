#include <stdio.h>
#define SIZE 100

int main()
{
    int arr[SIZE], n,i,gap,temp,j;
 printf("Enter the number of elements:");
    scanf("%d", &n);
     for (i = 0; i < n; i++)
    {
        printf("Enter arr[%d]:",i+1);
        scanf("%d",&arr[i]);
    
    }
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    printf("Sorted array is: [");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("] \n");

    return 0;
}