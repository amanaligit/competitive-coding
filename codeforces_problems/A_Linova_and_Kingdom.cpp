#include <bits/stdc++.h>
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
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================

//=======================

// bool compare(pair<int, int> p1, pair<int, int> p2)
// {
//     return (p1.second - p1.first) > (p2.second - p2.first);
// }
class Solution
{

public:
    vector<pair<int, int>> dp;
    vector<vector<int>> adj;
    vector<bool> marked;
    int n, k;
    vector<int> det;
    int dfs(int x, int d)
    {
        if (marked[x])
            return 0;
        dp[x].first = d + 1;
        marked[x] = true;
        int s = 0;
        for (size_t i = 0; i < adj[x].size(); i++)
        {
            s += dfs(adj[x][i], d + 1);
        }
        dp[x].second = s + 1;
        det[x] = dp[x].second - dp[x].first;
        return dp[x].second;
    }

    void solve()
    {
        cin >> n >> k;
        adj.resize(n, vi());
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            std::cin >> x >> y;
            adj[x - 1].push_back(y - 1);
            adj[y - 1].push_back(x - 1);
        }

        dp.resize(n);
        marked.resize(n, false);
        det.resize(n);
        dfs(0, 0);
        nth_element(det.begin(), det.begin() + n - k, det.end(), greater<int>());
        ll h = 0;
        for (size_t i = 0; i < n - k; i++)
        {
            h += det[i];
        }
        cout << h << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}