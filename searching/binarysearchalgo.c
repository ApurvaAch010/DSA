#include <stdio.h>
#define N 100

int binarySearch(int *arr, int target,int n)
{
    
    for (int i = 0; i < n - 1; i++)
    {
        int mainInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mainInd])
            {
                mainInd = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mainInd];
        arr[mainInd] = temp;
    }
    int left = 0, right = n;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[N],n;
    printf("Enter the number of elements:");
    scanf("%d", &n);

   for(int i=0;i<n;i++){
        
       
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }   

    int target;
    printf("Enter the target:");
    scanf("%d",&target);

    int result = binarySearch(arr, target,n);
    if (result != -1)
        printf("Target found in index [%d]\n",result);
    else
          printf("Target not found\n");
        
}
