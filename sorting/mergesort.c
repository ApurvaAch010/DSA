#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
    int a=mid-left+1;
    int b=right-mid;
    int leftarr[a],rightarr[b];
    for(int i=0;i<a;i++){
    leftarr[i]=arr[left+i];
    }
    for(int i=0;i<b;i++){
    rightarr[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<a&&j<b){
        if(leftarr[i]<=rightarr[j]){
            arr[k]=leftarr[i];
            i++;
        }
        else{
            arr[k]=rightarr[j];
            j++;
        }
        k++;
    }
    while(i<a){
        arr[k]=leftarr[i];
        i++;
        k++;
    }
    while(j<b){
        arr[k]=rightarr[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[],int left,int right){
    if(left>=right){
        return;
    }
    int mid=left+(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);

}


int main(){
    int n,arr[100];
    // cout<<"Enter the number of elements:";
    // cin>>n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    // cout<<"Enter the elements simulataneously:\n";
    printf("Enter the elements simulataneously:\n");
    for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }
     mergeSort(arr,0,n-1);
    //  cout<<"Sorted array:\n";
     printf("Sorted array:\n");
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
     }
    //  cout<<"endl";

    return 0;
}