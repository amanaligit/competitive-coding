#include <bits/stdc++.h>
#include <unordered_set>
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

class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;
        vi a(3);
        int n0 = 0, n1 = 0, n2 = 0;
        for (size_t i = 0; i < n; i++)
        {
            int tem;
            cin >> tem;
            int k = tem % 3;
            if (k == 0)
            {
                a[0]++;
            }
            else if (k == 1)
                a[1]++;
            else
                a[2]++;
        }
        int mi = 0;
        int li = 0;
        int count = 0;
        for (size_t i = 0; i < 3; i++)
        {
            if (a[i] > a[mi])
                mi = i;
            if (a[i] < a[li])
                li = i;
        }
        if (li == mi)
        {
            cout << 0 << endl;
            return;
        }
        int midi = 0;
        for (size_t i = 0; i < 3; i++)
        {
            if (i != mi && a[i] >= a[li] && i != li)
                midi = i;
        }
        while (a[mi] > n / 3 && a[li] < n / 3)
        {
            if (li == (mi + 1) % 3)
            {
                count++;
                a[mi]--;
                a[li]++;
            }
            else
            {
                count += 2;
                a[mi]--;
                a[li]++;
            }
        }
        while (a[mi] > n / 3 && a[midi] < n / 3)
        {
            if (midi == (mi + 1) % 3)
            {
                count++;
                a[mi]--;
                a[midi]++;
            }
            else
            {
                count += 2;
                a[mi]--;
                a[midi]++;
            }
        }
        while (a[li] < n / 3)
        {
            if (li == (midi + 1) % 3)
            {
                count++;
                a[midi]--;
                a[li]++;
            }
            else
            {
                count += 2;
                a[midi]--;
                a[li]++;
            }
        }
        cout << count << endl;
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