#include<iostream>
using namespace std;

int product(int a, int b){
    if(b == 0) return 0;         
    return a + product(a, b - 1);
}

int main(){
    int a ,b;
    cout<<"Enter the value of a and b:";
    cin>>a>>b;
    int result = product(a, b);
    cout << "Product: " << result << endl;
    return 0;
}
