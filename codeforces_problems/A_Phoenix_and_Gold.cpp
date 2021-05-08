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
typedef vector<bool> vb;
typedef vector<vb> vvb;
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

class Solution
{
public:
    vi w;
    int x;
    void solve()
    {
        int n;
        cin >> n >> x;
        w.resize(n);
        for (size_t i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            w[i] = temp;
        }
        sort(w.begin(), w.end());
        int sum = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (sum + w[i] == x)
            {
                if (i + 1 < n)
                    swap(w[i], w[i + 1]);
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            sum += w[i];
        }
        cout << "YES" << endl;
        for (auto var : w)
        {
            cout << var << " ";
        }
        cout << endl;
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