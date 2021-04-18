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
ll mod(ll value)
{
    ll m = value % MOD;
    if (m < 0)
        m += MOD;
    return m;
}
//=======================

class Solution
{
public:
    void solve()
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vpii pre(n + 1);
        pre[0] = make_pair(0, 0);
        for (size_t i = 0; i < n; i++)
        {
            pre[i + 1] = make_pair(pre[i].F + int(s[i] == 'a'), pre[i].S + int(s[i] == 'b'));
        }
        int i = 0, j = 0;
        int ans = 1;
        for (i = 0; i <= n - 1; i++)
        {
            if (j >= n)
                break;
            int as = pre[j + 1].F - pre[i].F;
            int bs = pre[j + 1].S - pre[i].S;
            int temp = j - i + 1;
            while (min(as, bs) <= k)
            {
                temp = j - i + 1;
                j++;
                if (j >= n)
                    break;
                as = pre[j + 1].F - pre[i].F;
                bs = pre[j + 1].S - pre[i].S;
            }
            ans = max(ans, temp);
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