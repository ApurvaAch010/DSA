//TOWER OF HANOI 3 DISK PROBLEM
#include<iostream>
using namespace std;
void TOH(int n, int A,int B,int C){
    if(n>0){
        cout<<"C:"<<C;
        TOH(n-1,A,C,B);
        cout<<"The disk move from:"<<A<<"to"<<C<<endl;
        TOH(n-1,B,A,C);
    }
}
int main(){
     int no=3,fdisk,sdisk,tdisk;
    
     cout<<"Enter the values of the disks[1st,2nd ,3rd]:";
     cin>>fdisk>>sdisk>>tdisk;
     TOH(no,fdisk,sdisk,tdisk);
     return 0;
    
}