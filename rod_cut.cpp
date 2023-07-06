#include <bits/stdc++.h>
using namespace std;
int memo[100000];
int rodcut(int n, int price[])
{
    if (n == 0)
        return 0;
    if (memo[n] != -1)
        return memo[n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, price[i] + rodcut(n - i, price));
    }
    memo[n] = ans;
    return memo[n];
}
int main()
{
    int n;
    cin >> n;
    int price[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << rodcut(n, price) << '\n';
    return 0;
}
