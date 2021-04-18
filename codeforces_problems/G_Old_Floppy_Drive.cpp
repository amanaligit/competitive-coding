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
    int bs(const vector<pair<ll, int>> &pre, int x, int left, int right)
    {
        int mid = (int)(right + left) / 2;
        if (left == right || pre[mid].F == x)
            return pre[mid].second;
        else if (x < pre[mid].F)
        {
            return bs(pre, x, left, mid);
        }
        else if (x > pre[mid].first)
        {
            return bs(pre, x, mid + 1, right);
        }
    }

    void solve()
    {
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, int>> pre;
        ll temp;
        cin >> temp;
        pre.push_back(make_pair(temp, 0));
        ll max = temp;
        ll toadd = 0;
        ll sum = temp;
        for (size_t i = 1; i < n; i++)
        {
            ll temp;
            cin >> temp;
            sum += temp;
            toadd += temp;
            if (toadd > 0)
            {
                pre.push_back(make_pair(pre.back().F + toadd, i));
                toadd = 0;
            }
            if (pre.back().F > max)
                max = pre.back().F;
        }
        for (size_t i = 0; i < m; i++)
        {
            ll x;
            cin >> x;
            if (x > max && sum <= 0)
            {
                cout << -1 << " ";
                continue;
            }
            ll spins = ceil((double)(x - max) / sum) > 0 ? ceil((double)(x - max) / sum) : 0;
            x -= spins * sum;
            cout << spins * n + bs(pre, x, 0, pre.size() - 1) << " ";
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