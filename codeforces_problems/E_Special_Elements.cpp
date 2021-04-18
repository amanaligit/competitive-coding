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
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        if (a.size())
        {
            for (size_t i = 0; i < a.size(); i++)
            {
                int l = 0, sum = 0;
                for (size_t j = 0; j < a.size(); j++)
                {
                    sum += a[j];
                    while (sum > a[i])
                    {
                        sum -= a[l];
                        l++;
                    }
                    if (sum == a[i])
                    {
                        if (j - l > 0)
                        {
                            ans++;
                            break;
                        }
                        else
                        {
                            l++;
                            sum = 0;
                        }
                    }
                }
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
    while (t--)
    {
        Solution sol;
        sol.solve();
    }

    return 0;
}