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
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<set<int>> sets(m);
        vector<int> sorted;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                int temp;
                cin >> temp;
                sets[j].insert(temp);
                sorted.push_back(temp);
            }
        }
        // mins
        set<pii> mins;
        for (int i = 0; i < sets.size(); i++)
            mins.insert({*sets[i].begin(), i});
        sort(sorted.begin(), sorted.end());
        int i = 0;
        int ans = INT_MAX;
        while (i < sorted.size())
        {
            int ele = sorted[i];
            bool works = true;
            while ((*mins.begin()).F < sorted[i])
            {
                pii p = *mins.begin();
                sets[p.S].erase(p.F);
                if (sets[p.S].empty())
                {
                    works = false;
                    break;
                }
                mins.erase(p);
                mins.insert({*(sets[p.S].begin()), p.S});
            }
            if (!works)
                break;
            ans = min(ans, (*mins.rbegin()).F - sorted[i]);
            i++;
        }
        cout << ans << endl;
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