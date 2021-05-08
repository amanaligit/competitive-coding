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
        vvi unis(n);
        vi u(n);
        for (int i = 0; i < n; i++)
        {
            cin >> u[i];
        }
        vi s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            unis[u[i] - 1].push_back(s[i]);
        }
        for (int i = 0; i < n; i++)
        {
            sort(unis[i].begin(), unis[i].end(), greater<int>());
        }
        vector<vl> pre(n, vl());
        for (int i = 0; i < n; i++)
        {
            pre[i].push_back(0);
            for (int j = 0; j < unis[i].size(); j++)
            {
                pre[i].push_back(pre[i][j] + unis[i][j]);
            }
        }
        vl ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (size_t k = 1; k <= unis[i].size(); k++)
            {
                int num = ((int)unis[i].size() / k) * k - 1;
                ans[k - 1] += pre[i][num + 1];
            }
        }
        for (size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
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