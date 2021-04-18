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
        ll A, B, n;
        cin >> A >> B >> n;
        vector<ll> b(n);
        vector<ll> a(b);
        ll maxa = 0;
        ll maxb = 0;
        ll suma;
        vector<ll> nf(n);
        for (size_t i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            a[i] = temp;
            maxa = max(a[i], maxa);
        }
        for (size_t i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            b[i] = temp;
        }
        for (size_t i = 0; i < n; i++)
        {
            nf[i] = b[i] % A ? b[i] / A + 1 : b[i] / A;
            B -= nf[i] * a[i];
        }
        if (B + maxa > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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