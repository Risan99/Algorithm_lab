#include <iostream>
using namespace std;

int findMax(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);

    return max(leftMax, rightMax);
}

int findMin(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftMin = findMin(arr, low, mid);
    int rightMin = findMin(arr, mid + 1, high);

    return min(leftMin, rightMin);
}

int main() {
    int n;
    cout << "Enter array elements number: ";
    cin >> n;

    int arr[n];
    cout << "Enter element: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxElement = findMax(arr, 0, n - 1);
    int minElement = findMin(arr, 0, n - 1);

    cout << "The maximum element in the array is: " << maxElement << endl;
    cout << "The minimum element in the array is: " << minElement << endl;

    return 0;
}