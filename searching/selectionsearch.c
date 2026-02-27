#include<stdio.h>
#define N 100

int targetCheck(int target,int arr[],int n){
    for(int i=0;i<n;i++){
        if(target==arr[i]){
            return i;
            break;
        }
    }
    return 0;

}
int main(){
    int arr[100],n;
 
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        
       
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target:");
    scanf("%d",&target);
    int result=targetCheck(target,arr,n);
    if(result==0){
        printf("Target not found\n");
        return 0;
    }
    
    printf("Target found in index [%d]\n",result);
  
    return 0;

}