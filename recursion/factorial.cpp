#include<iostream>
using namespace std;

int fact(int n){
    if(n==0||n==1){
        return 1;
    }
    
    return n*fact(n-1);
    
}
int main(){
    int x;
    cout<<"Enter a number for factorial:";
    cin>>x;
    int facto=fact(x);
    cout<<"The factorial of "<<x<<"! is:"<<facto<<endl;
    return 0;
}