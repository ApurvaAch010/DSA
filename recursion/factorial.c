#include<stdio.h>
int fact(int n){
    if(n==0||n==1){
        return 1;
    }
    
    return n*fact(n-1);
    
}
int main(){
    int x;
    printf("Enter a number for factorial:");
    scanf("%d",&x);
    int facto=fact(x);
    printf("The factorial of %d is %d",x,facto);
    return 0;
}