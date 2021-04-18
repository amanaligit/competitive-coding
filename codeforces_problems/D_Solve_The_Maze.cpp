#include <bits/stdc++.h>
using namespace std;
#include <unordered_set>
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
    vi marked;
    unordered_set<int> gp;
    unordered_set<int> mgp;
    void reach(int x, vvi &adj)
    {
        if (marked[x])
        {
            return;
        }
        marked[x] = true;
        if (gp.find(x) != gp.end())
        {
            mgp.insert(x);
        }
        for (size_t i = 0; i < adj[x].size(); i++)
        {
            reach(adj[x][i], adj);
        }
    }
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vvi maze(n, vi(m));
        int c = 1;

        for (size_t i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            int j = 0;
            for (auto ch : temp)
            {
                if (ch == '#')
                    maze[i][j] = 0;
                else if (ch == 'B')
                {
                    maze[i][j] = -1;
                }
                else
                {
                    if (ch == 'G')
                        gp.insert(c);
                    maze[i][j] = c;
                    c++;
                }
                j++;
            }
        }
        marked.resize(c, false);
        vvi adj(c);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m - 1; j++)
            {
                if (maze[i][j] == -1 && gp.find(maze[i][j + 1]) != gp.end())
                {
                    cout << "No" << endl;
                    return;
                }
                else if (maze[i][j + 1] == -1 && gp.find(maze[i][j]) != gp.end())
                {
                    cout << "No" << endl;
                    return;
                }
                if (maze[i][j] == -1 && maze[i][j + 1] != -1)
                    maze[i][j + 1] = 0;
                else if (maze[i][j + 1] == -1 && maze[i][j] != -1)
                    maze[i][j] = 0;
            }
        }
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n - 1; j++)
            {
                if (maze[j][i] == -1 && gp.find(maze[j + 1][i]) != gp.end())
                {
                    cout << "No" << endl;
                    return;
                }
                else if (maze[j + 1][i] == -1 && gp.find(maze[j][i]) != gp.end())
                {
                    cout << "No" << endl;
                    return;
                }
                if (maze[j][i] == -1 && maze[j + 1][i] != -1)
                    maze[j + 1][i] = 0;
                else if (maze[j + 1][i] == -1 && maze[j][i] != -1)
                    maze[j][i] = 0;
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m - 1; j++)
            {
                if (maze[i][j] && maze[i][j + 1] && maze[i][j] != -1 && maze[i][j + 1] != -1)
                {
                    adj[maze[i][j]].push_back(maze[i][j + 1]);
                    adj[maze[i][j + 1]].push_back(maze[i][j]);
                }
            }
        }
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n - 1; j++)
            {
                if (maze[j][i] && maze[j + 1][i] && maze[j][i] != -1 && maze[j + 1][i] != -1)
                {
                    adj[maze[j][i]].push_back(maze[j + 1][i]);
                    adj[maze[j + 1][i]].push_back(maze[j][i]);
                }
            }
        }
        reach(maze[n - 1][m - 1], adj);
        if (mgp.size() == gp.size())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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