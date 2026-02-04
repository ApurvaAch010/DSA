#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int x,y;
    cout<<"Enter x and y for gcd:";
    cin>>x>>y;
    cout<<"Gcd of "<<x<<"and"<<y<<"is :"<<gcd(x,y)<<endl;
    return 0;
}
