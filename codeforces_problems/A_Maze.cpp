#include <bits/stdc++.h>
#include <stdio.h>
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
    int n, m, k;
    vi marked;
    int count = 0;
    int c = 0;

    void reach(int x, vvi &adj)
    {
        if (marked[x] || count >= c - k)
        {
            return;
        }
        marked[x] = true;
        count++;

        for (size_t i = 0; i < adj[x].size(); i++)
        {
            reach(adj[x][i], adj);
        }
    }
    void solve()
    {
        cin >> n >> m >> k;
        vvi maze(n, vi(m));
        for (size_t i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            int j = 0;
            for (auto ch : temp)
            {
                if (ch == '#')
                    maze[i][j] = 0;
                else
                    maze[i][j] = ++c;
                j++;
            }
        }
        marked.resize(c + 1, false);
        vvi adj(c + 1);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m - 1; j++)
            {
                if (maze[i][j] && maze[i][j + 1])
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
                if (maze[j][i] && maze[j + 1][i])
                {
                    adj[maze[j][i]].push_back(maze[j + 1][i]);
                    adj[maze[j + 1][i]].push_back(maze[j][i]);
                }
            }
        }
        reach(1, adj);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                if (maze[i][j] == 0)
                    putchar('#');
                else if (marked[maze[i][j]])
                    putchar('.');
                else
                    putchar('X');
            }
            putchar('\n');
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}