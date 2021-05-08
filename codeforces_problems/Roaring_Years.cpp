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
    bool check(string y)
    {
        for (size_t i = 1; i < y.length(); i++)
        {
            bool flag = 0;
            string s = y.substr(0, i);
            int next = s.size();
            while (next < y.size())
            {
                int siz = to_string(stoll(s) + 1).size();
                if (next + siz > y.size())
                {
                    flag = 1;
                    break;
                }
                string t = y.substr(next, siz);
                if (t == to_string(stoll(s) + 1) && t[0] != '0')
                {
                    s = t;
                    next = next + s.size();
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            else
                return true;
        }
        return false;
    }
    void solve()
    {
        ll y;
        cin >> y;
        while (true)
        {
            y++;
            if (check(to_string(y)))
            {
                cout << y << endl;
                return;
            }
        }
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