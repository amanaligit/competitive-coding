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
    vi dijkstra(vector<unordered_map<int, int>> &adj, ll max_cost)
    {
        vector<long long> dist(adj.size(), max_cost + 1);
        vector<int> prev(adj.size(), -1);
        vector<bool> processed(adj.size(), false);
        dist[1] = 0;
        priority_queue<pair<long long, int>> pq;
        for (size_t i = 1; i < adj.size(); i++)
        {
            pq.push(make_pair(-dist[i], i));
        }
        while (!pq.empty())
        {
            pair<long long, int> u = pq.top();
            pq.pop();
            if (!processed[u.second])
            {
                for (auto edge : adj[u.second])
                {
                    if (dist[edge.first] > dist[u.second] + edge.second)
                    {
                        dist[edge.first] = dist[u.second] + edge.second;
                        prev[edge.first] = u.second;
                        pq.push(make_pair(-dist[edge.first], edge.first));
                    }
                }
                processed[u.second] = true;
            }
        }
        return prev;
    }
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<unordered_map<int, int>> adj(n + 1);
        ll max_cost = 0;
        for (size_t i = 0; i < m; i++)
        {
            int x, y, w;
            std::cin >> x >> y >> w;
            if (x != y)
            {
                if (adj[x][y])
                {
                    adj[x][y] = min(adj[x][y], w);
                    adj[y][x] = min(adj[y][x], w);
                }
                else
                {
                    adj[x][y] = w;
                    adj[y][x] = w;
                }
                max_cost += w;
            }
        }
        vi prev = dijkstra(adj, max_cost);
        if (prev[n] != -1)
        {
            vi ans;
            int node = n;
            while (node != -1)
            {
                ans.push_back(node);
                node = prev[node];
            }
            for (int i = ans.size() - 1; i >= 0; i--)
            {
                cout << ans[i] << " ";
            }
        }
        else
            cout << "-1";
        cout << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}