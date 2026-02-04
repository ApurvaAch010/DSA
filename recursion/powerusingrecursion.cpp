#include<iostream>
using namespace std;

int product(int a, int b){
    if(b == 0) return 0;          // anything times 0 is 0
    return a + product(a, b - 1); // add 'a' b times
}

int main(){
    int a = 5, b = 4;
    int result = product(a, b);
    cout << "Product: " << result << endl;
    return 0;
}
