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
        vi a(n + 1), b(n + 1);
        a[0] = 0;
        b[0] = 0;
        for (size_t i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
        }
        vi tm(n + 1);
        tm[0] = 0;
        for (size_t i = 1; i <= n; i++)
        {
            cin >> tm[i];
        }
        ll last = 0;
        for (size_t i = 1; i < n; i++)
        {
            ll arrival = last + tm[i] + a[i] - b[i - 1];
            ll time = ceil(((double)b[i] - a[i]) / 2);
            if (b[i] - arrival >= time)
                last = b[i];
            else
                last = arrival + time;
        }
        cout << last + tm[n] + a[n] - b[n - 1] << endl;
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