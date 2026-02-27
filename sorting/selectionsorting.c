#include <stdio.h>
#define N 100

int main()
{
    int n, arr[N], temp;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Enter values simulataneously:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
    }
    printf("Sorted array is: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("] \n");
    return 0;
}