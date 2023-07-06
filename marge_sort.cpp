#include <bits/stdc++.h>
using namespace std;
void marge(int arr[], int l, int mid, int r)
{
    int a[mid - l + 1], b[r - mid];
    for (int i = 0; i < mid - l + 1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < mid - l + 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    for (int j = 0; j < r - mid; j++)
    {
        b[j] = arr[mid + 1 + j];
    }
    for (int i = 0; i < r - mid; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    int i = 0, j = 0, k = l;
    while (i < mid - l + 1 && j < r - mid)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < mid - l + 1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < r - mid)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void margeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        margeSort(arr, l, mid);
        margeSort(arr, mid + 1, r);
        marge(arr, l, mid, r);
    }
}
int main()
{
    int arr[] = {1, 5, 7, 4, 2, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    margeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
