#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
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
//=======================
const ll MOD = 1000000007;
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
    unordered_map<ll, ll> dp;
    unordered_map<ll, ll> prefix;
    ll size = 1;
    ll t, k;

    ll ways(ll l)
    {
        if (dp[l])
            return dp[l];
        if (l == 0)
            return 1;

        ll ans = 0;
        ans = modulo(ans + ways(l - 1));
        if (l - k >= 0)
            ans = modulo(ans + ways(l - k));
        dp[l] = ans;
        return dp[l];
    }
    ll getPrefix(ll a, ll b)
    {
        if (b + 1 > size)
        {
            for (size_t i = size; i < b + 1; i++)
            {
                prefix[i] = modulo(prefix[i - 1] + ways(i));
            }
            size = b + 1;
        }
        return prefix[b] - prefix[a - 1];
    }
    void solve()
    {
        cin >> t >> k;
        prefix[0] = 0;
        for (size_t i = 0; i < t; i++)
        {
            ll a, b;
            cin >> a >> b;
            ll ans = modulo(getPrefix(a, b));
            cout << ans << endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution sol;
    sol.solve();
    return 0;
}