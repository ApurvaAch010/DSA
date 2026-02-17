#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int lno, n, arr1[100], hash[100], location;
    cout << "Enter the number of values:";
    cin >> n;
    cout << "Enter the number of locations:";
    cin >> lno;
    for (int i = 0; i < lno; i++)
        hash[i] = -1;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value [" << i + 1 << "]:";
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int j=1;
        int h=arr1[i] % lno;
        location = h;
        while (hash[location] != -1)
        {

            location = (h + j*j) % lno;
            count++;
            j++;
            if (count == lno)
            {
                cout << "Hash table is full.Cannot insert:" << arr1[i] << endl;
                break;
            }
        }
        if (count < lno)
        {
            hash[location] = arr1[i];
        }
    }
    cout << "\n Hash table:\n";
    for (int i = 0; i < lno; i++)
    {
        cout << i << "->" << hash[i] << endl;
    }
    return 0;
}