//TOWER OF HANOI 3 DISK PROBLEM
#include<stdio.h>
void TOH(int n, int A,int B,int C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("MOVE DISKS: %d from %d to %d",n,A,C);
        TOH(n-1,B,A,C);
    }
}
int main(){
     int no=3,fdisk,sdisk,tdisk;
    
    
     printf("Enter the values of the disks [1st,2nd,3rd]");
     scanf("%d %d %d",fdisk,sdisk,tdisk);
     TOH(no,fdisk,sdisk,tdisk);
     return 0;
    
}