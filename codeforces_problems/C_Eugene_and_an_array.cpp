#include <bits/stdc++.h>
using namespace std;
#include <unordered_set>
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
        ll sum = 0;
        set<ll> sums = {0};
        ll ans = 0;
        vector<ll> pre(n + 1);
        for (size_t i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            pre[i] = pre[i - 1] + a;
        }
        int l = 0, r = 0;
        while (l < n)
        {
            //repeat until a duplicate element is encountered
            while (r < n && sums.find(pre[r + 1]) == sums.end())
            {
                r++;
                sums.insert(pre[r]);
            }
            //if duplicate count is encountered
            ans = ans + (r - l);
            //remove the element l is pointing to from the set
            sums.erase(pre[l]);
            //increment the value of l
            l++;
        }
        cout << ans << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}