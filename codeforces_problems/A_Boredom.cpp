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
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================

//=======================

class Solution
{
public:
    void solve()
    {
        vector<ll> a(100001, 0);
        int n;
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            int tem;
            cin >> tem;
            a[tem]++;
        }
        int s = 0;
        vector<ll> dp(100001);
        dp[0] = 0;
        dp[1] = a[1];
        for (ll i = 2; i < dp.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);
        }
        cout << dp[100000] << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}