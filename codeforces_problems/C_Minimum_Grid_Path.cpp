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
        int n;
        cin >> n;
        vl c(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        vl mino(n + 1), mine(n + 1);
        mino[0] = LLONG_MAX;
        mine[0] = LLONG_MAX;
        mino[1] = c[1];
        mine[1] = c[0];
        for (size_t i = 1; i < n - n / 2; i++)
        {
            mine[i + 1] = min(mine[i], c[2 * i]);
        }
        for (size_t i = 1; i < n / 2; i++)
        {
            mino[i + 1] = min(mino[i], c[2 * i + 1]);
        }
        vl sume(n + 1), sumo(n + 1);
        sumo[0] = 0;
        sume[0] = 0;
        for (size_t i = 0; i < n - n / 2; i++)
        {
            sume[i + 1] = sume[i] + c[2 * i];
        }
        for (size_t i = 0; i < n / 2; i++)
        {
            sumo[i + 1] = sumo[i] + c[2 * i + 1];
        }
        ll ans = LLONG_MAX;
        for (size_t i = 1; i < n - n / 2 + 1; i++)
        {
            ll ans0 = sume[i] - mine[i] + mine[i] * (n - i + 1);
            ll ans1 = LLONG_MAX;
            if (i - 1 > 0)
                ans1 = sumo[i - 1] - mino[i - 1] + mino[i - 1] * (n - (i - 1) + 1);
            if (2 * i <= n)
                ans1 = min((ll)(sumo[i] - mino[i] + mino[i] * (n - i + 1)), ans1);
            ans = min(ans, ans1 + ans0);
        }
        cout << ans << endl;
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