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
    ll n, k, d;

    void solve()
    {
        int r, c;
        cin >> r >> c;
        vvi mat(r, vi(c));
        priority_queue<pair<int, pair<int, int>>> pq;
        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                cin >> mat[i][j];
                pq.push(make_pair(mat[i][j], make_pair(i, j)));
            }
        }
        vvi done(r, vi(c, 0));
        ll ans = 0;
        while (!pq.empty())
        {
            pair<int, pair<int, int>> t = pq.top();
            pq.pop();
            if (!done[t.S.F][t.S.S])
            {
                done[t.S.F][t.S.S] = 1;
                int row = t.S.F;
                int col = t.S.S;
                int val = mat[row][col];
                if (row < r - 1)
                {
                    if (mat[row + 1][col] < val - 1)
                    {
                        ans += val - 1 - mat[row + 1][col];
                        mat[row + 1][col] += val - 1 - mat[row + 1][col];
                        pq.push(make_pair(mat[row + 1][col], make_pair(row + 1, col)));
                    }
                }
                if (row > 0)
                {
                    if (mat[row - 1][col] < val - 1)
                    {
                        ans += val - 1 - mat[row - 1][col];
                        mat[row - 1][col] += val - 1 - mat[row - 1][col];
                        pq.push(make_pair(mat[row - 1][col], make_pair(row - 1, col)));
                    }
                }
                if (col < c - 1)
                {
                    if (mat[row][col + 1] < val - 1)
                    {
                        ans += val - 1 - mat[row][col + 1];
                        mat[row][col + 1] += val - 1 - mat[row][col + 1];
                        pq.push(make_pair(mat[row][col + 1], make_pair(row, col + 1)));
                    }
                }
                if (col > 0)
                {
                    if (mat[row][col - 1] < val - 1)
                    {
                        ans += val - 1 - mat[row][col - 1];
                        mat[row][col - 1] += val - 1 - mat[row][col - 1];
                        pq.push(make_pair(mat[row][col - 1], make_pair(row, col - 1)));
                    }
                }
            }
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