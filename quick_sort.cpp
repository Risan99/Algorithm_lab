#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int lb, int ub)
{
    int st = lb;
    int end = ub;
    int pivot = arr[lb];
    while (st < end)
    {
        while (arr[st] <= pivot)
        {
            st++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (st < end){
            swap(arr[st], arr[end]);
        }
    }
    swap(arr[end], arr[lb]);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    partition(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
