#include <stdio.h>
#include <math.h>
int main()
{
    int i,count,lno, n, arr1[100], hash[100], location;
 printf("Enter the number of values:");
    scanf("%d",&n);
    printf("Enter the number of locations:");
    scanf("%d",&lno);
    for (i = 0; i < lno; i++)
        hash[i] = -1;
    for (i = 0; i < n; i++)
    {
        printf("Enter value [%d]:",i+1);
        scanf("%d",&arr1[i]);
    }

    for (i = 0; i < n; i++)
    {
        count = 0;
        location = floor(arr1[i] % lno);
        while (hash[location] != -1)
        {

            location = (location + 1) % lno;
            count++;
            if (count == lno)
            {
                printf("Hash table is full cannot insert %d\n",arr1[i]);
                break;
            }
        }
        if (count < lno)
        {
            hash[location] = arr1[i];
        }
    }
    printf("\n Hash table:\n");
    for (i = 0; i < lno; i++)
    {
        printf("%d -> %d \n",i,hash[i]);
    }
    return 0;
}