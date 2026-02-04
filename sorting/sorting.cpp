#include <iostream>
#define N 100
using namespace std;
int main()
{
    int n, arr[N], temp;
    cout << "Enter the number of arrays";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the [" << i << "]" << "element:";
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
        }
        cout << "arr[i]:" << arr[i] << endl;
        cout << "arr[minInd]]:" << arr[minInd] << endl;
        int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
        cout << "The value of new array is [";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ",";
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