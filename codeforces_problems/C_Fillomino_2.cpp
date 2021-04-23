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
        int n;
        cin >> n;
        vi p(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        vvi grid(n, vi(n, -1));
        for (size_t i = 0; i < n; i++)
        {
            grid[i][i] = p[i];
        }
        for (size_t i = 0; i < n; i++)
        {
            int ii = i;
            int j = i;
            int ctr = 1;
            bool d = 1;
            while (ctr < p[i])
            {
                if (d)
                {
                    while (j - 1 >= 0 && grid[ii][j - 1] == -1 && ctr < p[i])
                    {
                        ctr++;
                        j--;
                        grid[ii][j] = p[i];
                    }
                    d = !d;
                }
                else
                {
                    while (ii + 1 < n && grid[ii + 1][j] == -1 && ctr < p[i] && grid[ii][j - 1] != -1)
                    {
                        ctr++;
                        ii++;
                        grid[ii][j] = p[i];
                    }
                    d = !d;
                }
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j <= i; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
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