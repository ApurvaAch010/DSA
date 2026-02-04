#include<iostream>
#define N 100
using namespace std;

void heapSort(int arr1[],int n){
    //for making a binary treee
    int bt[n];
    for(int i=n/2-1;i>=0;i--){
        for(int j=2*i+2;j<n-1;){
            if(i<j){
                bt[i]=arr1[i];
            }
            else bt[j]=arr1[j];
        }
    }
    cout<<"Arrayy:"<<endl;
    for(int i=0;i<n;i++){
        cout<<bt[i]<<" ";
    }
    

}


int main(){
    int n=6;
    int arr[6]={15,18,20,10,9,11};
    // cout<<"Enter the number of elements:";
    // cin>>n;
    

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter [" << i << "] element:";
    //     cin >> arr[i];
    // }


    heapSort(arr,n);

}