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

// bool ctree(int x, int y)
// {
//     return sizes[x] > sizes[y];
// }

class Solution
{
public:
    vector<ll> sizes;
    ll reach(vector<vector<int>> &adj, int x, int parent)
    {
        ll size = 1;
        for (size_t i = 0; i < adj[x].size(); i++)
        {
            if (adj[x][i] == parent)
                continue;
            size += reach(adj, adj[x][i], x);
        }
        sizes[x] = size;
        return size;
    }

    void solve()
    {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> adj(n);
        sizes.resize(n);
        for (size_t i = 0; i < n - 1; i++)
        {
            int a, b;
            std::cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }
        // if (adj[x - 1].size() <= 1)
        // {
        //     cout << "AYUSH" << endl;
        //     return;
        // }
        vector<ll> cs;

        reach(adj, x - 1, -1);
        for (size_t i = 0; i < adj[x - 1].size(); i++)
        {
            cs.push_back(sizes[adj[x - 1][i]]);
        }
        sort(cs.begin(), cs.end());
        ll nos = 0;
        for (size_t i = 0; i < cs.size() - 1; i++)
        {
            nos += sizes[cs[i]];
        }
        string ans = nos % 2 ? "Ashish" : "Ayush";
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