#include <iostream>
#define SIZE 100
using namespace std;
int main()
{
    int arr[SIZE], n;
    cout << "Enter the number of elements:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter [" << i << "] element:";
        cin >> arr[i];
    }
    for (int gap = n - 1 / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
       for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

        cout<<endl;

        return 0;
}