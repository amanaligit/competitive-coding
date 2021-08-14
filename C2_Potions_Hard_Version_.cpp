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
    void solve()
    {
        int n;
        cin >> n;
        vi arr(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        priority_queue<int> pq;
        int ans = 0;
        ll curr = 0;

        for (size_t i = 0; i < n; i++)
        {
            if (curr + arr[i] >= 0)
            {
                ans++;
                pq.push(-arr[i]);
                curr += arr[i];
            }
            else if (pq.size())
            {
                int top = -pq.top();
                if (top < arr[i])
                {
                    pq.pop();
                    curr -= top;
                    curr += arr[i];
                    pq.push(-arr[i]);
                }
            }
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