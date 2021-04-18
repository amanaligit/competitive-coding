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
    void solve()
    {
        int n, d;
        cin >> n >> d;
        vpii f(n);
        for (size_t i = 0; i < n; i++)
        {
            int m, s;
            cin >> m >> s;
            f[i] = make_pair(m, s);
        }
        sort(f.begin(), f.end());
        vector<ll> pre(n + 1, 0);
        for (size_t i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + f[i].second;
        }
        int l = 0, r = 0;
        ll ans = 0;

        while (f[r].first - f[l].first < d && l < n)
        {
            while (r < n && f[r].first - f[l].first < d)
                r++;
            r--;
            ans = max(ans, pre[r + 1] - pre[l]);
            l++;
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