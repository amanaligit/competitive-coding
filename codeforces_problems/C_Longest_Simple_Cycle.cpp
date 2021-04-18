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
        vector<ll> chain(n);
        for (size_t i = 0; i < n; i++)
            cin >> chain[i];
        vector<ll> a(n + 1, -1);
        for (size_t i = 0; i < n; i++)
            cin >> a[i];
        vector<ll> b(n + 1, -1);
        for (size_t i = 0; i < n; i++)
            cin >> b[i];
        ll count = abs(a[1] - b[1]);
        ll max_count = abs(a[1] - b[1]);

        for (size_t chain_index = 1; chain_index < chain.size(); chain_index++)
        {

            count += 2;
            ll A = a[chain_index + 1];
            ll B = b[chain_index + 1];
            ll break_chain = chain[chain_index] - 1;
            max_count = max(max_count, break_chain + count);
            if (A != B)
            {
                if (B > A)
                    count = max(A - 1 + chain[chain_index] - B + count, B - A);
                else
                    count = max(A - B, B - 1 + chain[chain_index] - A + count);
                max_count = max(max_count, count);
            }
            else
                count = 0;
        }
        cout << max_count << endl;
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