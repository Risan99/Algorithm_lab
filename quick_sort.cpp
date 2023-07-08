#include <bits/stdc++.h>
using namespace std;

int part(int s, int e, int arr[])
{
    int pind = s;
    int pivot = arr[e];
    // int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[pind], arr[i]);
            pind++;
        }
    }
    swap(arr[pind], arr[e]);
    return pind;
}
void quicksort(int s, int e, int arr[])
{
    if (s < e)
    {
        int pind = part(s, e, arr);
        quicksort(s, pind - 1, arr);
        quicksort(pind + 1, e, arr);
    }
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
    quicksort(0, n - 1, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
