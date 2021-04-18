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

class Solution
{
public:
    vector<bool> c;
    vector<bool> mar;
    int n, m;
    ll reach(vector<vector<int>> &adj, int x, ll cats)
    {
        if (!mar[x])
        {
            mar[x] = 1;
            if (c[x])
            {
                cats++;
                if (cats > m)
                    return 0;
            }
            else
            {
                cats = 0;
            }
            if (adj[x].size() == 1 && mar[adj[x][0]])
            {
                return 1;
            }
            ll ans = 0;
            for (size_t i = 0; i < adj[x].size(); i++)
            {
                ans += reach(adj, adj[x][i], cats);
            }
            return ans;
        }
        else
            return 0;
    }
    void solve()
    {

        cin >> n >> m;
        mar.resize(n + 1);
        c.resize(n + 1);
        for (size_t i = 1; i < n + 1; i++)
        {
            bool temp;
            cin >> temp;
            c[i] = temp;
        }

        vector<vector<int>> adj(n + 1, vector<int>());
        for (size_t i = 0; i < n - 1; i++)
        {
            int x, y;
            std::cin >> x >> y;
            adj[y].push_back(x);
            adj[x].push_back(y);
        }
        cout << reach(adj, 1, 0) << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}