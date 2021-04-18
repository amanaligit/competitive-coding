#include <bits/stdc++.h>
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
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================

//=======================

class Solution
{
public:
    void solve()
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<pair<int, int>> queries;
        for (size_t i = 0; i < q; i++)
        {
            int s, e;
            cin >> s >> e;
            queries.push_back(make_pair(s, e));
        }

        vector<pair<pair<int, int>, int>> prefix(n + 1, make_pair(make_pair(0, 0), 0));
        int maxval = 0, minval = 0, currval = 0;

        for (size_t i = 1; i <= s.size(); i++)
        {
            if (s[i - 1] == '+')
            {
                currval++;
                maxval = max(maxval, currval);
            }
            else
            {
                currval--;
                minval = min(minval, currval);
            }
            prefix[i].first = make_pair(maxval, minval);
            prefix[i].second = currval;
        }

        vector<pair<int, int>> suffix(n + 1, make_pair(0, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '+')
            {
                suffix[i] = make_pair(max(suffix[i + 1].first + 1, 0), min(suffix[i + 1].second + 1, 0));
            }
            else
            {
                suffix[i] = make_pair(max(suffix[i + 1].first - 1, 0), min(suffix[i + 1].second - 1, 0));
            }
        }

        for (size_t i = 0; i < q; i++)
        {
            int s = queries[i].first;
            int e = queries[i].second;
            maxval = max(prefix[s - 1].first.first, prefix[s - 1].second + suffix[e].first);
            minval = min(prefix[s - 1].first.second, prefix[s - 1].second + suffix[e].second);
            cout << maxval - minval + 1 << endl;
        }
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