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
ll modulo(ll value)
{
    ll mod = value % MOD;
    if (mod < 0)
        mod += MOD;
    return mod;
}
//=======================

class Solution
{
public:
    vector<vector<ll>> dp;
    vl a;
    ll rec(int l, int r)
    {
        if (dp[l][r] != -1)
            return dp[l][r];
        else if (l == r)
            return 0;
        else
        {
            dp[l][r] = min(rec(l + 1, r), rec(l, r - 1)) + a[r] - a[l];
            return dp[l][r];
        }
    }

    void solve()
    {
        int n;
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            a.push_back(t);
        }
        sortall(a);
        dp.resize(n, vl(n, -1));
        cout << rec(0, n - 1) << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}