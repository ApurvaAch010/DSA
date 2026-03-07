#include <stdio.h>

int main()
{
    int arr[100], n, i, key, j;
    printf("Enter the value of n:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter [%d] element", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array is: [");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("] \n");
}
