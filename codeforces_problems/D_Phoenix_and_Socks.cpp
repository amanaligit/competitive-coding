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
        int n, l, r;
        cin >> n >> l >> r;

        unordered_map<int, int> m1, m2;
        for (size_t i = 0; i < l; i++)
        {
            int temp;
            cin >> temp;
            m1[temp]++;
        }
        for (size_t i = 0; i < r; i++)
        {
            int temp;
            cin >> temp;
            m2[temp]++;
        }
        if (r > l)
        {
            swap(m1, m2);
            swap(l, r);
        }
        int ans = 0;
        for (size_t i = 1; i <= n; i++)
        {
            int delta = min(m1[i], m2[i]);
            m1[i] -= delta;
            m2[i] -= delta;
            l -= delta;
            r -= delta;
        }
        for (auto s : m1)
        {
            if (l > r)
            {
                int delta = min((l - r) / 2, (m1[s.F] / 2));
                ans += delta;
                l -= delta * 2;
                m1[s.F] -= delta * 2;
            }
        }
        while (l > r)
        {
            ans++;
            l--;
            r++;
        }
        ans += l;
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