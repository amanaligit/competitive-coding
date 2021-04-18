#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n * i < n : i > n; k < n *i += 1 : i -= 1)
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
        cin >> n;
        vector<string> s(n, "");
        for (size_t i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        vector<string> pre(n, "");
        vector<string> middle(n, "");
        vector<string> post(n, "");
        for (size_t i = 0; i < n; i++)
        {
            size_t start = s[i].find('*');
            pre[i] = s[i].substr(0, start);
            size_t end = start + 1;
            for (size_t j = start; j < s[i].size(); j++)
            {
                if (s[i][j] == '*')
                    end = j + 1;
            }
            for (size_t j = start + 1; j < end - 1; j++)
            {
                if (s[i][j] != '*')
                    middle[i] += s[i][j];
            }
            while (end < s[i].size() && s[i][end] == '*')
                end++;
            if (end < s[i].size())
                post[i] = s[i].substr(end, s[i].size());
        }
        string big = "";
        for (size_t i = 0; i < n; i++)
        {
            if (pre[i].size() > big.size())
                big = pre[i];
        }
        string ans;
        ans += big;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < pre[i].size(); j++)
            {
                if (pre[i][j] != big[j])
                {
                    cout << "*" << endl;
                    return;
                }
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            ans += middle[i];
        }
        big = "";
        for (size_t i = 0; i < n; i++)
        {
            if (post[i].size() > big.size())
                big = post[i];
        }
        for (size_t i = 0; i < n; i++)
        {
            for (int j = 1; j <= post[i].size(); j++)
            {
                if (post[i][post[i].size() - j] != big[big.size() - j])
                {
                    cout << "*" << endl;
                    return;
                }
            }
        }
        ans += big;
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