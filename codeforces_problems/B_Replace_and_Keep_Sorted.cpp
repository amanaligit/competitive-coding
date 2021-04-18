#include <bits/stdc++.h>
#include <unordered_set>
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
        int n, q, k;
        cin >> n >> q >> k;
        vi a(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vi dp(n, 0);
        for (size_t j = 0; j < n; j++)
        {
            if (j < n - 1)
                dp[j] += a[j + 1] - a[j] - 1;
            if (j > 0)
                dp[j] += a[j] - a[j - 1] - 1;
        }
        vi pre(n + 1, 0);
        for (size_t i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + dp[i];
        }

        for (size_t i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l == r)
            {
                cout << k - 1 << endl;
                continue;
            }
            ll c = a[l] - 1 + k - a[r] + a[l + 1] - a[l] - 1 + a[r] - a[r - 1] - 1;

            cout << c + pre[r] - pre[l + 1] << endl;
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