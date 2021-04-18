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
        vector<int> nums(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<ll> freq(n + 1, 0);
        for (size_t i = 0; i < q; i++)
        {
            int a, b;
            cin >> a >> b;
            freq[a - 1]++;
            freq[b]--;
        }
        for (size_t i = 1; i < freq.size(); i++)
        {
            freq[i] += freq[i - 1];
        }
        sort(freq.begin(), freq.end());
        sortall(nums);
        ll ans = 0;
        for (int i = freq.size() - 1; i >= 1; i--)
        {
            ans += nums[i - 1] * freq[i];
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