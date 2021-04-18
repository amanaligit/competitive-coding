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
    int go(vi &a, vi &b)
    {
        if (b.empty())
            return 0;
        int aptr = -1, bptr = -1, p = 0;
        queue<int> bq;
        unordered_set<int> bm;
        for (size_t i = 0; i < b.size(); i++)
            bm.insert(b[i]);
        int nc = 0;
        while (!a.empty() && a.back() > b.back())
            a.pop_back();
        for (size_t i = 0; i < a.size(); i++)
        {
            if (bm.find(a[i]) != bm.end())
                nc++;
        }
        int s = 0;
        int ans = 0;
        while (aptr < (int)a.size() - 1 || bptr < (int)b.size() - 1)
        {
            if (aptr == (int)a.size() - 1 || a[aptr + 1] > b[bptr + 1])
            {
                bptr++;
                p = b[bptr] - s;
                bq.push(b[bptr]);
            }
            else
            {
                aptr++;
                p = a[aptr] - 1 - s;
                s++;
                if (bm.find(a[aptr]) != bm.end())
                {
                    nc--;
                    bq.push(a[aptr]);
                    bptr++;
                }
            }

            while (!bq.empty() && bq.front() < p + 1)
                bq.pop();
            ans = max(ans, (int)bq.size() + nc);
        }
        return ans;
    }

    void solve()
    {
        int n, m;
        cin >> n >> m;
        vi a(n);
        vi b(m);
        for (size_t i = 0; i < n; i++)
            cin >> a[i];
        for (size_t i = 0; i < m; i++)
            cin >> b[i];
        vi ap, an, bp, bn;
        int inda = n, indb = m;
        for (size_t i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                inda = i;
                break;
            }
        }
        for (size_t i = 0; i < m; i++)
        {
            if (b[i] > 0)
            {
                indb = i;
                break;
            }
        }
        for (int i = inda - 1; i >= 0; i--)
            an.push_back(-a[i]);
        for (int i = inda; i < n; i++)
            ap.push_back(a[i]);
        for (int i = indb - 1; i >= 0; i--)
            bn.push_back(-b[i]);
        for (int i = indb; i < m; i++)
            bp.push_back(b[i]);
        int ans1 = go(ap, bp);
        int ans2 = go(an, bn);
        cout << ans1 + ans2 << endl;
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