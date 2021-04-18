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
    bool cmatch(char a, char b)
    {
        if (b == '.')
            return true;
        return a == b;
    }
    bool matchrec(string &s, string &p, size_t ps, size_t pp, vvi &dp)
    {
        if (pp == p.size())
        {
            if (pp == p.size() && ps == s.size())
                return true;
            return false;
        }
        if (dp[ps][pp] != -1)
            return dp[ps][pp];
        char c = p[pp];
        if (pp < p.size() - 1 && p[pp + 1] == '*')
        {
            if (matchrec(s, p, ps, pp + 2, dp))
            {
                dp[ps][pp] = 1;
                return 1;
            }
            int i = 0;
            while (ps + i < s.size() && cmatch(s[ps + i], p[pp]))
            {
                i++;
                if (ps < s.size() && matchrec(s, p, ps + i, pp + 2, dp))
                {
                    dp[ps][pp] = 1;
                    return 1;
                }
            }
            dp[ps][pp] = 0;
            return false;
        }
        else
        {
            if (ps < s.size() && cmatch(s[ps], p[pp]))
            {
                dp[ps][pp] = matchrec(s, p, ps + 1, pp + 1, dp);
                return dp[ps][pp];
            }
            else
            {
                dp[ps][pp] = false;
                return false;
            }
        }
    }
    bool isMatch(string s, string p)
    {
        // int ptr = p;
        vvi dp(s.size() + 1, vi(p.size() + 1, -1));
        return matchrec(s, p, 0, 0, dp);
    }
};