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
    vi path;
    vi visits;
    void dfs(vector<vector<int>> &adj, int x, int a)
    {
        path.push_back(x);
        visits[x]++;
        for (size_t i = 0; i < adj[x].size(); i++)
        {
            dfs(adj, adj[x][i], a);
        }
        int k = (int)path.size() - a - 1;
        if (k >= 0)
            visits[path[k]] += visits[x];
        path.pop_back();
    }

    void solve()
    {
        int a, b;
        cin >> n >> a >> b;
        vvi adj(n);
        for (size_t i = 1; i < n; i++)
        {
            int t;
            cin >> t;
            adj[--t].push_back(i);
        }
        visits.resize(n, 0);
        dfs(adj, 0, a);
        vector<long double> pa(n);
        for (size_t i = 0; i < n; i++)
        {
            pa[i] = (long double)visits[i] / n;
        }
        for (size_t i = 0; i < visits.size(); i++)
        {
            visits[i] = 0;
        }
        dfs(adj, 0, b);
        vector<long double> pb(n);
        for (size_t i = 0; i < n; i++)
        {
            pb[i] = (long double)visits[i] / n;
        }
        long double ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            ans += pa[i] + pb[i] - pa[i] * pb[i];
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