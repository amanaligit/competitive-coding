
// Sample code to perform I/O:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long rec(int i, vector<vector<long long>> &dp, int n, bool last)
{
    if (i == n - 1)
    {
        dp[last][i] = last ? 1 : 2;
        return dp[last][i];
    }
    if (dp[last][i] != -1)
    {
        return dp[last][i];
    }
    if (last)
    {
        dp[last][i] = rec(i + 1, dp, n, 0);
        return dp[last][i];
    }
    dp[last][i] = rec(i + 1, dp, n, 0) + rec(i + 1, dp, n, 1);
    return dp[last][i];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        if (n == 1)
        {
            if (k == 1)
                cout << 'O' << endl;
            else if (k == 2)
                cout << 'Z' << endl;
            else
                cout << -1 << endl;
            continue;
        }
        vector<vector<long long>> dp(2, vector<long long>(n + 1, -1));
        // cout<<"reacjed"<<endl;
        long long total = rec(1, dp, n, 0) + rec(1, dp, n, 1);
        dp[0].back() = dp[1].back() = 1;
        if (k > total)
        {
            cout << -1 << endl;
            continue;
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (dp[0][i + 1] >= k)
            {
                ans += 'O';
            }
            else
            {
                ans += "ZO";
                k -= dp[0][i + 1];
                i += 1;
            }
        }
        // cout<<total<<endl;
        cout << ans << endl;
    }
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here
