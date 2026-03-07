#include<stdio.h>
#define N 100


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int t, temp;

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;

    return i + 1;
}

void quicksort(int arr[], int i, int j)
{
    if (i < j)
    {
        int pi = partition(arr, i, j);

        quicksort(arr, i, pi - 1);
        quicksort(arr, pi + 1, j);
    }
}
int main()
{
    int arr[N], n,i;
   printf("Enter the number of elements:");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("Enter [%d] element", i + 1);
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n-1);
    printf("Sorted array:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n");
    return 0;
}