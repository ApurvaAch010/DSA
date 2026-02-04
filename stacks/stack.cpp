#include<iostream>
using namespace std;
#define SIZE 5

int sp=-1;
int arr[SIZE];

void push(int x){
    sp++;
    if(sp>SIZE){
      cout<<"STACK OVERLOADED";  
    }
    arr[sp]=x;
}

void pop(){
    if(sp==-1){
        cout<<"STACK UNDERFLOWED";
    }
    cout<<"Popped stack:"<<arr[sp]<<endl;
    sp--;
    
}
void topelement(){
    if(sp==-1){
        cout<<"STACK UNDERFLOWED";
    }

    cout<<"TOP OF STACK:"<<arr[sp]<<endl;
}
int main(){
    int a,d;
    cout<<"1=>PUSH/ 2=>POP:";
    cin>>a;
    
    if(a==1){
        cout<<"Enter the number you wanna push:";
        cin>>d;
        push(d);
        
    }
    else if(a==2){
        pop();
    }else{
        topelement();
    }
   


    return 0;
}
