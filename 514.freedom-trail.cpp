// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
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
    vvi dp;
    string ring;
    string key;
    unordered_map<char, vector<int>> pos;

    int rec(int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 1;
        if (i + 1 < key.size())
        {
            dp[i][j] = INT_MAX;
            for (auto next : pos[key[i + 1]])
            {
                dp[i][j] = min(dp[i][j], 1 + min(abs(j - next), min((int)ring.size() - next + j, (int)ring.size() - j + next)) + rec(i + 1, next));
            }
        }
        return dp[i][j];
    }

    int findRotateSteps(string ring, string key)
    {
        this->ring = ring;
        this->key = key;

        dp.resize(key.size(), vi(ring.size(), -1));

        for (int i = 0; i < ring.size(); i++)
        {
            pos[ring[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto next : pos[key[0]])
        {
            ans = min(ans, min(next, (int)ring.size() - next) + rec(0, next));
        }
        return ans;
    }
};
// @lc code=end
