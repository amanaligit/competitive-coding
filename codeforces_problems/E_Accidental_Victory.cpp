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
        vpii t(n);
        for (size_t i = 0; i < n; i++)
        {
            int token;
            cin >> token;
            t[i] = make_pair(token, i);
        }
        sortall(t);
        vl pre(n + 1);
        pre[0] = 0;
        for (size_t i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + t[i].first;
        }
        vector<bool> win(n, false);
        win[t[n - 1].second] = true;
        int count = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (pre[i + 1] < t[i + 1].first)
                break;
            win[t[i].second] = true;
            count++;
        }
        cout << count << endl;
        for (size_t i = 0; i < n; i++)
        {
            if (win[i])
                cout << i + 1 << " ";
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