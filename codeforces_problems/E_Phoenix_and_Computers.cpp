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
typedef vector<bool> vb;
typedef vector<vb> vvb;
//=======================
int MOD = 1'000'000'007;
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
    // C++ implementation to find nCr
    // Function to find the nCr
    ll fact[405], inv[405], choose[405][405], pow2[405];
    int n;
    ll fastexp(ll b, ll exp)
    {
        if (exp == 0)
            return 1;
        ll temp = fastexp(b, exp / 2);
        temp = (temp * temp) % MOD;
        if (exp % 2 == 1)
            temp *= b;
        return temp % MOD;
    }
    void precompute()
    {
        fact[0] = 1;
        inv[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = (fact[i - 1] * i) % MOD;
            inv[i] = fastexp(fact[i], MOD - 2);
        }
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i; j++)
                choose[i][j] = ((fact[i] * inv[j]) % MOD * inv[i - j]) % MOD;
        for (int i = 0; i <= n; i++)
            pow2[i] = fastexp(2, i);
    }
    void solve()
    {
        cin >> n >> MOD;
        vector<vl> dp(n + 2, vl(n + 2, 0));
        precompute();
        dp[0][0] = 1;
        
        // for (size_t l = 0; l < n; l++)
        // {
        //     for (size_t c = 0; c <= l; c++)
        //     {
        //         for (size_t k = 1; l + k <= n; k++)
        //         {

        //             dp[l + k + 1][c + k] = mod(dp[l + k + 1][c + k] + dp[l][c] * mod(fact[c + k] / mod(fact[c] * fact[k])) * pows[k - 1]);
        //         }
        //     }
        // }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                for (int k = 1; i + k <= n; k++)
                {
                    dp[i + k + 1][j + k] += ((dp[i][j] * pow2[k - 1]) % MOD * choose[j + k][k]);
                    // cout << i + k + 1 << " " << j + k << dp[i + k + 1][j + k] << endl;
                    dp[i + k + 1][j + k] %= MOD;
                }
            }
        }
        ll ans = 0;
        for (size_t i = 0; i <= n; i++)
        {
            ans = mod(ans + dp[n + 1][i]);
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