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
ll n, k, d;
unordered_map<ll, unordered_map<bool, ll>> dp;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = d == 0;
    for (ll i = 1; i <= n; i++)
    {
        ll ways0 = 0;
        for (ll j = 1; j <= min(d - 1, i); j++)
        {
            ways0 = (ways0 + dp[i - j][0]) % MOD;
        }
        dp[i][0] = ways0;

        ll ways = 0;
        for (ll j = 1; j <= min(d - 1, i); j++)
        {
            ways = (ways + dp[i - j][1]) % MOD;
        }
        for (ll j = d; j <= min(i, k); j++)
        {
            ways = (ways + dp[i - j][1] + dp[i - j][0]) % MOD;
        }
        dp[i][1] = ways;
    }

    cout << dp[n][1] % MOD << endl;

    return 0;
}