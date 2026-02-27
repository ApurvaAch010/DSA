#include<stdio.h>
int product(int a, int b){
    if(b == 0) return 0;         
    return a + product(a, b - 1);
}

int main(){
    int a ,b;
    printf("Enter the value of a and b:");
    scanf("%d %d",&a,&b);
    int result = product(a, b);
    printf("Product %d",result);
    return 0;
}
