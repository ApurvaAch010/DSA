#include <iostream>
#include <vector>
using namespace std;

// Selection sort function cause what type of data is not sure
vector<int> sortarray(vector<int> arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int mainInd = i;
        for(int j = i+1; j < n; j++) { 
            if(arr[j] < arr[mainInd]) {
                mainInd = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mainInd];
        arr[mainInd] = temp;
    }
    return arr;
}

int binarySearch(vector<int> arr, int target) {
    vector<int> sortedArr = sortarray(arr); 
    int left = 0, right = sortedArr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(sortedArr[mid] == target) return mid;
        else if(sortedArr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cout << "Enter [" << i << "] value of array: ";
        cin >> arr[i];
    }

    int target;
    cout << "Enter the number to search in the array: ";
    cin >> target;

    int result = binarySearch(arr, target);
    if(result != -1) cout << "Number found at index: " << result << endl;
    else cout << "Number not found in the array" << endl;
}
