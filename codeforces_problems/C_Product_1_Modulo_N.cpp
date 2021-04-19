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
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    void solve()
    {
        int n;
        cin >> n;
        vi a;
        for (size_t i = 1; i < n; i++)
        {
            a.push_back(i);
        }
        vi ans;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (gcd(a[i], n) == 1)
                ans.push_back(a[i]);
        }

        ll prod = 1;
        for (size_t i = 0; i < ans.size(); i++)
        {
            prod = (prod * ans[i]) % n;
        }
        if (prod != 1)
        {
            cout << ans.size() - 1 << endl;
            for (size_t i = 0; i < ans.size(); i++)
            {
                if (ans[i] != prod)
                    cout << ans[i] << " ";
            }
            return;
        }
        cout << ans.size() << endl;
        for (size_t i = 0; i < ans.size(); i++)
        {

            cout << ans[i] << " ";
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