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
const int MOD = 100000000;
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
    int k1, k2;
    vector<vector<vector<int>>> dp;

    ll rec(int n1, int n2, bool last)
    {
        if (n1 == 0 && n2 == 0)
            return 1;
        if (dp[last][n1][n2] != -1)
            return dp[last][n1][n2];
        else
        {
            ll ans = 0;
            if (last)
            {
                for (int i = 1; i <= min(n2, k2); i++)
                {
                    ans += rec(n1, n2 - i, 0);
                }
            }
            else
            {
                for (int i = 1; i <= min(n1, k1); i++)
                {
                    ans += rec(n1 - i, n2, 1);
                }
            }
            dp[last][n1][n2] = mod(ans);
            return dp[last][n1][n2];
        }
    }

    void solve()
    {
        int n1, n2;
        cin >> n1 >> n2 >> k1 >> k2;
        ll ans1 = 0, ans2 = 0;
        dp.resize(2, vvi(n1 + 1, vi(n2 + 1, -1)));
        for (size_t i = 1; i <= min(n1, k1); i++)
        {
            ans1 = mod(ans1 + rec(n1 - i, n2, 1));
        }
        for (size_t i = 1; i <= min(n2, k2); i++)
        {
            ans2 = mod(ans2 + rec(n1, n2 - i, 0));
        }

        cout << mod(ans1 + ans2) << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution sol;
    sol.solve();
    return 0;
}