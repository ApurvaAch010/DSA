#include <iostream>
#define N 100
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int t, temp;

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;

    return i + 1;
}

void quicksort(int arr[], int i, int j)
{
    if (i < j)
    {
        int pi = partition(arr, i, j);

        quicksort(arr, i, pi - 1);
        quicksort(arr, pi + 1, j);
    }
}
int main()
{
    int arr[N], n;
    cout << "Enter the number of elements:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the [" << i << "] element:";
        cin >> arr[i];
    }
    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}