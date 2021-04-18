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
        int r, c;
        cin >> r >> c;
        vector<vector<char>> mat(r, vector<char>(c));
        unordered_set<char> ch;
        for (size_t i = 0; i < r; i++)
        {
            string s;
            cin >> s;
            for (size_t j = 0; j < c; j++)
            {
                mat[i][j] = s[j];
                ch.insert(mat[i][j]);
            }
        }
        unordered_map<char, unordered_set<char>> mp;
        for (size_t i = 0; i < r - 1; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                if (mat[i][j] != mat[i + 1][j])
                    mp[mat[i][j]].insert(mat[i + 1][j]);
            }
        }
        string ans;
        unordered_map<char, bool> put;
        while (ans.size() != ch.size())
        {
            int k = ans.size();
            for (auto var : ch)
            {
                if (!put[var])
                {
                    bool yes = true;
                    for (auto var2 : mp[var])
                    {
                        yes = yes && put[var2];
                    }
                    if (yes)
                    {
                        ans.push_back(var);
                        put[var] = true;
                    }
                }
            }
            if (k == ans.size())
            {
                cout << -1 << endl;
                return;
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