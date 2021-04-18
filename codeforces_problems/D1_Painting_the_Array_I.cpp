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
        int n;
        cin >> n;
        vi a(n);
        unordered_map<int, queue<int>> dp;
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
            dp[a[i]].push(i);
        }
        ll seg = 0;
        int x = 0, y = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (x != a[i] && y != a[i])
            {
                int nexta1 = INT_MAX, nexta2 = INT_MAX;
                if (dp[x].size())
                    nexta1 = dp[x].front();
                if (dp[y].size())
                    nexta2 = dp[y].front();
                if (nexta1 < nexta2)
                    x = a[i];
                else
                    y = a[i];
                seg++;
            }
            else if (x == a[i])
            {
                if (y != a[i])
                    seg++;
                y = a[i];
            }
            else
            {
                seg++;
                x = a[i];
            }
            dp[a[i]].pop();
        }

        cout << seg << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}