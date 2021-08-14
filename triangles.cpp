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
    void solve()
    {
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        vector<vector<int>> pre(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vi(n, 0));
        for (size_t i = 0; i < n; i++)
        {
            pre[i].back() = !mat[i].back();
            for (int j = n - 2; j >= 0; j--)
            {
                if (!mat[i][j])
                {
                    dp[i][j] = 1;
                    pre[i][j] = 1 + pre[i][j + 1];
                }
            }
        }
        vector<int> mp(n + 1);
        mp[3] = 1;
        for (size_t i = 5; i <= n; i += 2)
        {
            mp[i] = mp[i - 2] * 3 + 1;
        }

        int ans = 0;
        for (size_t i = 1; i < n; i++)
        {
            int last = -1;
            for (size_t j = 0; j < n - 1; j++)
            {
                dp[i][j] = min(pre[i][j], dp[i - 1][j + 1] + 2);
                if (last != -1)
                {
                    if (j + dp[i][j] > last + dp[i][last])
                    {
                        ans += mp[dp[i][j]] - mp[last + dp[i][last] - j];
                    }
                }
                else
                    ans += mp[dp[i][j]];
            }
        }
        cout << ans << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution sol;
    sol.solve();
    return 0;
}