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
    vvi components;
    void reach(vector<vector<int>> &adj, int x, int parent, vector<bool> &marked, const int &id)
    {
        if (marked[x])
            return;
        marked[x] = true;
        components[id].push_back(x);
        for (size_t i = 0; i < adj[x].size(); i++)
        {
            reach(adj, adj[x][i], x, marked, id);
        }
    }

    void solve()
    {
        int m, n;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1, vector<int>());
        for (size_t i = 0; i < m; i++)
        {
            int x, y;
            std::cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> marked(n + 1, false);
        int id = 1;
        components.resize(n + 1);
        for (size_t i = 1; i <= n; i++)
        {
            if (!marked[i])
            {
                reach(adj, i, -1, marked, id);
                id++;
            }
        }
        int ans = 0;
        for (size_t j = 0; j < components.size(); j++)
        {
            vi component = components[j];
            if (component.size() >= 3)
            {
                bool cycle = true;
                for (size_t i = 0; i < component.size(); i++)
                {
                    cycle = cycle && adj[component[i]].size() == 2;
                }
                if (cycle)
                    ans++;
            }
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