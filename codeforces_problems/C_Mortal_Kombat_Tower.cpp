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
const ll MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================

//=======================

class Solution
{
public:
    int n;
    vi b;

    ll rec(int i, int even, vector<vector<ll>> &dp)
    {
        if (dp[i][even] != -1)
            return dp[i][even];
        if (i >= n)
            return 0;
        else
        {
            ll ans1 = 0, ans2 = 0;
            if (even)
            {
                ans1 = b[i] + rec(i + 1, false, dp);
                ans2 = b[i] + b[i + 1] + rec(i + 2, false, dp);
            }
            else
            {
                ans1 = rec(i + 1, true, dp);
                ans2 = rec(i + 2, true, dp);
            }
            dp[i][even] = min(ans1, ans2);
            return dp[i][even];
        }
    }
    void solve()
    {
        cin >> n;
        b.resize(n + 1, 0);
        for (size_t i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<vector<ll>> dp(n + 2, {-1, -1});
        cout << (rec(0, true, dp) + MOD) % MOD << endl;
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