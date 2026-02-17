#include <iostream>
using namespace std;
struct Chain
{
    int data;
    struct Chain *next;
};

struct Chain *getChain()
{
    struct Chain *newChain = (struct Chain *)malloc(sizeof(struct Chain));
    if (newChain == NULL)
    {
        cout << "Error alloacting memory";
        exit(1);
    }
    return newChain;
}
int main()
{
    int arr1[100], n, lno;
    Chain *hashtable[100];
    cout << "Enter the number of elements:";
    cin >> n;
    cout << "Enter the number of hashtable locations:";
    cin >> lno;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value [" << i + 1 << "]:";
        cin >> arr1[i];
    }
    for (int i = 0; i < lno; i++)
        hashtable[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int h = arr1[i] % lno;
       
        Chain *newChain=getChain();
        newChain->data=arr1[i];
        newChain->next=NULL;
        if(hashtable[h]==0){
            hashtable[h]=newChain;
        }
        else{
            newChain->next=hashtable[h];
            hashtable[h]=newChain;
        }
    }
    for(int i=0;i<lno;i++){
        struct Chain *temp=hashtable[i];
        while(temp!=NULL){
            cout<<"Hashtable ["<<i<<"]:"<<temp->data<<endl;
            temp=temp->next;
        }
    }
}