#include <stdio.h>
#include <math.h>

int main()
{
    int i,j,h1,h2,count, lno, n, arr1[100], hash[100], location;
   
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
        j=0;
        h1=arr1[i] % lno;
        h2=1+(arr1[i]%lno-1);
        location = h1;
        while (hash[location] != -1)
        {

          j++;
           
            location=(j+h1*h2)%lno;
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