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
        int n, m;
        cin >> n >> m;
        vvi b(n + 1, vi(m + 1));
        priority_queue<pair<int, pair<int, int>>> pq;
        vvb taken(n + 1, vb(m + 1, 0));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                cin >> b[i][j];
                pq.push(make_pair(-b[i][j], make_pair(i, j)));
            }
        }
        vvi ans(n + 1, vi(m + 1, -1));
        for (size_t i = 0; i < m; i++)
        {
            auto q = pq.top();
            pq.pop();
            taken[q.S.F][q.S.S] = 1;
            ans[q.S.F][i] = -q.F;
        }
        for (size_t i = 0; i < n; i++)
        {
            int ctr = 0;
            for (size_t j = 0; j < m; j++)
            {
                if (ans[i][j] != -1)
                {
                    continue;
                }
                while (taken[i][ctr])
                {
                    ctr++;
                }
                ans[i][j] = b[i][ctr];
                ctr++;
            }
        }

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
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