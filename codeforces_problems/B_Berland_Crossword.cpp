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
    void solve()
    {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool ans = 0;
        for (size_t i = 0; i < 2; i++)
        {
            for (size_t j = 0; j < 2; j++)
            {
                for (size_t k = 0; k < 2; k++)
                {
                    for (size_t m = 0; m < 2; m++)
                    {
                        bool y = 1;
                        y = y && (u - (i + j) >= 0 && u - (i + j) <= n - 2);
                        y = y && (r - (j + k) >= 0 && r - (j + k) <= n - 2);
                        y = y && (d - (k + m) >= 0 && d - (k + m) <= n - 2);
                        y = y && (l - (m + i) >= 0 && l - (m + i) <= n - 2);
                        if (y)
                            ans = 1;
                    }
                }
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        Solution sol;
        sol.solve();
    }
    return 0;
}