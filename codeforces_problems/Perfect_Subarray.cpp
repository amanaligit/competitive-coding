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
    int n, k, d;

    void solve()
    {
        cin >> n;
        vi a(n);
        int sum = 0;
        int maxa = INT_MIN;
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += abs(a[i]);
            maxa = max(maxa, a[i]);
        }
        vi squares;
        int i = 0;
        while (i * i <= n * maxa)
        {
            squares.push_back(i * i);
            i++;
        }
        vi p(2 * sum + 1, 0);
        p[sum] = 1;
        ll pre = 0;
        ll ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            pre += a[i];
            for (size_t i = 0; i < squares.size(); i++)
            {
                int s = squares[i];
                if (pre - s + sum < 0)
                    break;
                ans += p[pre - s + sum];
            }
            p[pre + sum]++;
        }
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