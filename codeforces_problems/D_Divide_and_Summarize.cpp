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
    unordered_map<ll, bool> dp;

    ll Sum(vector<ll> &a, int start, int end)
    {
        if (start == end)
        {
            dp[a[start]] = true;
            return a[start];
        }
        if (end < start)
        {
            return 0;
        }

        int mid = (a[start] + a[end]) / 2;
        int mid_pos = my_binary_search(a, mid, start, end);
        ll sum;
        if (mid_pos != end)
        {
            sum = Sum(a, start, mid_pos) + Sum(a, mid_pos + 1, end);
            dp[sum] = true;
        }
        else
        {
            sum = (end - start + 1) * a[end];
            dp[sum] = true;
        }

        return sum;
    }
    int my_binary_search(const vector<ll> &a, int x, int left, int right)
    {
        //int left = 0, right = (int)a.size();
        int mid = (int)(right + left) / 2;
        if (a[mid] == x)
        {
            int i = mid;
            while (i < a.size() && a[i] == x)
            {
                i++;
            }
            return --i;
        }
        else if (left == right)
            return left - 1;
        else if (x < a[mid])
        {
            //std::copy(a.begin(), mid, v.begin());
            return my_binary_search(a, x, left, mid);
        }

        //vector<int> v;
        //std::copy(mid+1, a.end(), v.begin());
        return my_binary_search(a, x, mid + 1, right);
    }

    void solve()
    {
        int n, q;
        cin >> n >> q;
        vector<ll> a;

        for (size_t i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        Sum(a, 0, n - 1);
        for (size_t i = 0; i < q; i++)
        {
            ll sum;
            cin >> sum;
            string ans = dp[sum] ? "Yes" : "No";
            cout << ans << endl;
        }
    }
};

//write your code here

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