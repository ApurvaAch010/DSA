#include <stdio.h>
#include <math.h>

int main()
{
    int lno, n, arr1[100], hash[100], location;
    printf("Enter the number of values:");
    scanf("%d", &n);
    printf("Enter the number of locations:");
    scanf("%d", &lno);
    for (int i = 0; i < lno; i++)
        hash[i] = -1;
    for (int i = 0; i < n; i++)
    {
        printf("Enter value [%d]:", i + 1);
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int j = 1;
        int h = arr1[i] % lno;
        location = h;
        while (hash[location] != -1)
        {

            location = (h + j * j) % lno;
            count++;
            j++;
            if (count == lno)
            {
                printf("Hash table is full cannot insert %d\n", arr1[i]);
                break;
            }
        }
        if (count < lno)
        {
            hash[location] = arr1[i];
        }
    }
    printf("\n Hash table:\n");
    for (int i = 0; i < lno; i++)
    {
        printf("%d -> %d \n", i, hash[i]);
    }
    return 0;
}