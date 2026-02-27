#include<stdio.h>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int x,y;
    printf("Enter x and y for gcd:");
    scanf("%d %d",&x,&y);
    printf("Gcd of %d id %d",x,gcd(x,y));
    return 0;
}
