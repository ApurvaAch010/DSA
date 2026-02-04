#include <iostream>
#define N 100
using namespace std;
int main()
{
    int arr[N], n, temp;
    cout << "Enter the value of n:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the [" << i << "]" << "element:";
        cin >> arr[i];
    };
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "The value of new array is [";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
    return 0;
}