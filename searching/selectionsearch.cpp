#include<iostream>
#define N 100
using namespace std;
int targetCheck(int target,int arr[],int n){
    for(int i=0;i<n;i++){
        if(target==arr[i]){
            return i;
            break;
        }
    }
    return 0;

}
int main(){
    int arr[100],n;
    cout<<"Enter the number of elements:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter ["<<i+1<<"] element:";
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target:";
    cin>>target;
    int result=targetCheck(target,arr,n);
    if(result==0){
        cout<<"Target Not found"<<endl;
        return 0;
    }
    cout<<"Target Found in "<<result<<" index"<<endl;
  
    return 0;

}