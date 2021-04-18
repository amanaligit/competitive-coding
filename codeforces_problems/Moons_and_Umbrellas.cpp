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
    ll n, k, d;

    void solve()
    {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        ll ans = 0;
        int k = 0;
        while (s[k] == '?')
            k++;
        int i = k;
        while (i < int(s.length()) - 1)
        {
            if (s[i] != '?')
            {
                if (s[i] == 'C' && s[i + 1] == 'J')
                    ans += x;
                if (s[i] == 'J' && s[i + 1] == 'C')
                    ans += y;
                i++;
            }
            else
            {
                int next = i + 1;
                while (next < int(s.length()) && s[next] == '?')
                    next++;
                if (s[next] == s[i - 1])
                    i = next;
                if (next == int(s.length()) - 1 && s[next] == '?')
                    break;
                if (s[next] == 'J' && s[i - 1] == 'C')
                    ans += x;
                if (s[next] == 'C' && s[i - 1] == 'J')
                    ans += y;
                i = next;
            }
        }
        cout << ans << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int temp = t;
    while (t--)
    {
        Solution sol;
        cout << "Case #" << temp - t << ": ";
        sol.solve();
    }
    return 0;
}