#include <stdio.h>
#define SIZE 100

int main()
{
    int arr[SIZE], n;
 printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Enter values simulataneously:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }
    for (int gap = n - 1 / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    printf("Sorted array is: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("] \n");

    return 0;
}