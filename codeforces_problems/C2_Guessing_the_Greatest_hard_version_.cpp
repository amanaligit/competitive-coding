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
    int smax;
    void rec1(int l, int r)
    {
        if (l == r)
        {
            cout << "! " << l << endl;
            cout.flush();
            return;
        }
        if (r - l == 1)
        {
            cout << "? " << l << " " << r << endl;
            cout.flush();
            int pos;
            cin >> pos;
            int ans = pos == l ? r : l;
            cout << "! " << ans << endl;
            cout.flush();
            return;
        }
        int mid = (l + r) / 2;
        cout << "? " << mid << " " << smax << endl;
        cout.flush();
        int pos;
        cin >> pos;
        if (pos == smax)
        {
            rec1(mid, r);
        }
        else
        {
            rec1(l, mid - 1);
        }
    }
    void rec2(int l, int r)
    {
        if (l == r)
        {
            cout << "! " << l << endl;
            cout.flush();
            return;
        }
        if (r - l == 1)
        {
            cout << "? " << l << " " << r << endl;
            cout.flush();
            int pos;
            cin >> pos;
            int ans = pos == l ? r : l;
            cout << "! " << ans << endl;
            cout.flush();
            return;
        }
        int mid = (l + r) / 2;
        cout << "? " << smax << " " << mid << endl;
        cout.flush();
        int pos;
        cin >> pos;
        if (pos == smax)
        {
            rec2(l, mid);
        }
        else
        {
            rec2(mid + 1, r);
        }
    }
    void solve()
    {
        int n;
        cin >> n;
        // if (n == 2)
        // {
        //     cout << "? " << 1 << " " << 2 << endl;
        //     cout.flush();
        //     int pos;
        //     cin >> pos;
        //     int ans = pos == 1 ? 2 : 1;
        //     cout << "! " << ans << endl;
        //     cout.flush();
        //     return;
        // }
        cout << "? " << 1 << " " << n << endl;
        cout.flush();
        cin >> smax;
        if (smax > 1)
        {
            cout << "? " << 1 << " " << smax << endl;
            cout.flush();
            int v;
            cin >> v;
            if (smax == v)
            {
                rec1(1, smax - 1);
            }
            else
            {
                rec2(smax + 1, n);
            }
        }
        else
        {
            rec2(smax + 1, n);
        }
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution sol;
    sol.solve();
    return 0;
}