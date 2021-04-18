#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define F first
#define S second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vb> vvb;

//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================
ll mod(ll value)
{
    ll m = value % MOD;
    if (m < 0)
        m += MOD;
    return m;
}
//=======================

class Solution
{
public:
    int rec(vvi &grid, int i, int j, vvb v)
    {
        v[i][j] = 1;
        if (grid[i][j] == 2)
        {
            cout << "reached end" << endl;
            for (size_t i = 0; i < v.size(); i++)
            {
                for (size_t j = 0; j < v[0].size(); j++)
                {
                    if (!v[i][j] && grid[i][j] != -1)
                        return 0;
                }
            }
            return 1;
        }
        else if (grid[i][j] == -1)
            return 0;
        int ways = 0;
        if (i > 0 && !v[i - 1][j])
            ways += rec(grid, i - 1, j, v);
        if (i < grid.size() - 1 && !v[i + 1][j])
            ways += rec(grid, i + 1, j, v);
        if (j > 0 && !v[i][j - 1])
            ways += rec(grid, i, j - 1, v);
        if (j < grid[0].size() - 1 && !v[i][j + 1])
            ways += rec(grid, i, j + 1, v);
        return ways;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        vvb visited(grid.size(), vb(grid[0].size(), 0));
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    visited[i][j] = 1;
                    return rec(grid, i, j, visited);
                }
            }
        }
        return 0;
    }
};