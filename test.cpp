#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int get_answer(vector<vector<int>> &arr, int n)
{
    // cout << "good";
    int winner = 0;
    for (int a = 0; a < n - 1; a++)
    {
        int score = 0;
        for (int b = 0; b < 5; b++)
        {
            if (arr[winner][b] < arr[a + 1][b])
                score++;
        }
        if (score < 3)
            winner = a + 1;
    }
    bool flag = false;
    for (int a = 0; a < n - 1; a++)
    {
        if (a != winner)
        {
            int score = 0;
            for (int b = 0; b < 5; b++)
            {
                if (arr[winner][b] < arr[a + 1][b])
                    score++;
            }
            if (score < 3)
            {
                winner = -2;
                // flag = true;
                break;
            }
        }
    }
    return winner + 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // cout << "good";
        int n;
        cin >> n;
        vector<vector<int>> array(n, vector<int>(5, 0));
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < 5; b++)
            {
                cin >> array[a][b];
            }
        }
        if (n == 1)
            cout << 1 << endl;
        if (n > 1)
        {
            // cout << "good2testcase";/
            int ans = get_answer(array, n);
            cout << ans << endl;
        }
    }
    return 0;
}