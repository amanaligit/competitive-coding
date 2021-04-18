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
    void rec(int l, int r, int val)
    {
        if (l == r)
        {
            cout << "! " << l << endl;
            cout.flush();
            return;
        }
        if (r - l == 2)
        {
            cout << "? " << l + 1 << " " << r << endl;
            cout.flush();
            int val2;
            cin >> val2;
            if (val != val2 && val != l)
            {
                cout << "! " << l << endl;
                cout.flush();
                return;
            }
            else
            {
                int ans = val2 == l + 1 ? l + 2 : l + 1;
                cout << "! " << ans << endl;
                cout.flush();
                return;
            }
        }
        if (r - l == 1)
        {
            int ans = val == l ? r : l;
            cout << "! " << ans << endl;
            cout.flush();
            return;
        }
        int mid = (l + r) / 2;
        cout << "? " << l << " " << mid << endl;
        cout.flush();
        int val2;
        cin >> val2;
        if (val == val2)
        {
            rec(l, mid, val2);
            return;
        }
        cout << "? " << mid + 1 << " " << r << endl;
        cout.flush();
        int val3;
        cin >> val3;
        if (val == val2 || ((val >= mid + 1 && val <= r) && val3 != val))
            rec(l, mid, val2);
        else if (val == val3 || (val <= mid && val != val2))
            rec(mid + 1, r, val3);
    }
    void solve()
    {

        int n;
        cin >> n;
        cout << "? " << 1 << " " << n << endl;
        cout.flush();
        int val;
        cin >> val;
        rec(1, n, val);
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution sol;
    sol.solve();
    return 0;
}