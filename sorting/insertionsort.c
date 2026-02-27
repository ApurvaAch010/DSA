#include<stdio.h>

int main() {
    int arr[100], n;
    printf("Enter hte value of n:");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Enter [%d] element",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array:");
    for(int i = 0; i < n; i++)
        printf("%d",arr[i]);
}
