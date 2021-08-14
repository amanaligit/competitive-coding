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

bool show = true;

class Solution
{
public:
    ll n, k, d;

    void solve()
    {
        ll c;
        cin >> n >> c;
        vector<pair<ll, int>> points;
        for (size_t i = 0; i < n; i++)
        {
            ll t1,
                t2;
            cin >> t1 >> t2;
            points.push_back({t1, 1});
            points.push_back({t2, 0});
        }

        sortall(points);
        priority_queue<pair<ll, pair<ll, ll>>> pq;

        ll count = 0;
        ll start = -1;
        priority_queue<ll> ends;
        ll lastEp = points[0].first;

        ll lastPushed = -1;
        for (size_t i = 0; i < points.size(); i++)
        {
            auto p = points[i];
            if (start != -1)
                pq.push({count, {start, p.F}});
            start = p.F;

            if (!p.S)
            {
                // int bruh = i;
                count--;
                while (i + 1 < points.size() && points[i + 1] == points[i])
                {
                    i++;
                    count--;
                }
                ends.push(count);
                lastPushed = points[i].first;
            }
            else
            {
                if (points[i].first != lastPushed)
                {
                    ends.push(count);
                    lastPushed = points[i].first;
                }
                count++;
                while (points[i + 1] == points[i])
                {
                    i++;
                    count++;
                }
            }
        }
        ll k = 0;
        ll cuts = 0;

        while (cuts < c && (pq.size() || ends.size()))
        {
            if (ends.empty() || (pq.size() && pq.top().first > ends.top()))
            {
                auto p = pq.top();
                pq.pop();
                ll curr = min(c - cuts, max(p.S.S - p.S.F - 1, 0ll));
                k += curr * p.F;
                cuts += curr;
            }
            else
            {
                cuts += 1;
                k += ends.top();
                ends.pop();
            }
        }

        cout << k + n << endl;
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
        // show = (temp - t) == 13;
        Solution sol;
        cout << "Case #" << temp - t << ": ";
        sol.solve();
    }
    return 0;
}