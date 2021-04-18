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
    string s;

    bool go(int j)
    {
        bool ans = true;
        for (int i = 0; i < j - 1; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1')
                ans = 0;
        }
        for (int i = j + 1; i < int(s.size()) - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '0')
                ans = 0;
        }
        return ans;
    }

    void solve()
    {
        cin >> s;
        bool ans = 0;
        for (int i = 0; i <= int(s.size()); i++)
        {
            if (i == int(s.size()) || s[i] == '1')
                ans = ans || go(i);
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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