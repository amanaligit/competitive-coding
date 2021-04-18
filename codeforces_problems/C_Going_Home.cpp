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
const int N = 5000005, M = N;
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
        vpii mp(N);
        int n;
        cin >> n;
        vi a(n + 1);
        for (size_t i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
            {
                int tmp = a[j] + a[i];
                if (!mp[tmp].F)
                    mp[tmp] = make_pair(i, j);
                else if (mp[tmp].F != j && mp[tmp].S != i && mp[tmp].S != j && mp[tmp].F != i)
                {
                    cout << "YES" << endl;
                    printf("%d %d %d %d", mp[tmp].F, mp[tmp].S, i, j);
                    return;
                }
            }
        puts("NO");
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution sol;
    sol.solve();
    return 0;
}