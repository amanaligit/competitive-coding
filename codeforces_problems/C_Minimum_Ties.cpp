#include <bits/stdc++.h>
#include <unordered_set>
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
    void solve()
    {
        int n;
        cin >> n;
        vvi mat(n, vi(n));
        vi nw(n, 0);
        vi nd(n, 0);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                if (n % 2)
                {
                    if (nw[i] < n / 2)
                    {
                        mat[i][j] = i;
                        nw[i]++;
                    }
                    else
                    {
                        mat[i][j] = j;
                        nw[j]++;
                    }
                }
                else
                {
                    if (nw[i] < n / 2 - 1)
                    {
                        mat[i][j] = i;
                        nw[i]++;
                    }
                    else if (!nd[i])
                    {
                        mat[i][j] = -1;
                        nd[i]++;
                        nd[j]++;
                    }
                    else
                    {
                        mat[i][j] = j;
                        nw[j]++;
                    }
                }
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                int ans;
                if (mat[i][j] == -1)
                    ans = 0;
                else if (mat[i][j] == i)
                    ans = 1;
                else
                    ans = -1;
                cout << ans << " ";
            }
        }
        cout << endl;
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