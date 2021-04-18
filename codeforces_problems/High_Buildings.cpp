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
    int k, d, n;
    void solve()
    {
        int c, a, b;
        cin >> n >> a >> b >> c;
        int s = n - (a + b - c);
        if (s < 0 || (a == 1 && b == 1 && c == 1 && n > 1))
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        vi ans(n, 1);
        int i;
        for (i = 0; i < a - c; i++)
        {
            ans[i] = 2;
        }
        int count = 0;
        int j = n - 1;
        while (++count <= b - c)
        {
            ans[j] = 2;
            j--;
        }
        count--;
        if (a > b)
        {
            while (++count <= b - b / 2)
            {
                ans[i] = 3;
                i++;
            }
            count--;
            while (++count <= b)
            {
                ans[j] = 3;
                j--;
            }
        }
        else
        {
            while (++count <= b - b / 2)
            {
                ans[j] = 3;
                j--;
            }
            count--;
            while (++count <= b)
            {
                ans[i] = 3;
                i++;
            }
        }
        for (size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
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