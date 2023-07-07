#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);  // Call function to sort the elements

    cout << "Sorted elements are : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}