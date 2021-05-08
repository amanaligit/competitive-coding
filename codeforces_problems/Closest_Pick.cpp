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
        int n, k;
        cin >> n >> k;
        vi p(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        sortall(p);
        double w1 = 0, w2 = 0;
        if (1 < p.front())
        {
            double num = p.front() - 1;
            w1 = max(w1, num);
        }
        for (size_t i = 0; i < n - 1; i++)
        {
            double num = p[i + 1] - p[i] - 1;
            if (w1 > w2)
                swap(w1, w2);
            if (w1 < ceil((num) / 2))
            {
                w1 = ceil((num) / 2);
                w2 = max(w2, num - w1);
            }
        }
        if (w1 > w2)
            swap(w1, w2);
        if (k > p.back())
        {
            double num = k - p.back();
            w1 = max(w1, num);
        }
        double ans = (w1 + w2) / k;
        cout << ans << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int temp = t;
    while (t--)
    {
        Solution sol;
        cout << "Case #" << temp - t << ": ";
        sol.solve();
    }
    return 0;
}