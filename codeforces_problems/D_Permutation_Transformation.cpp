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
    vi arr;
    vi segtree;
    vi tree;
    int n;
    vi d;

    void constructSTUtil(vi arr, int ss, int se, int si)
    {
        if (ss > se)
            return;
        if (ss == se)
        {
            segtree[si] = ss;
            return;
        }

        int mid = (ss + se) / 2;
        constructSTUtil(arr, ss, mid, si * 2 + 1);
        constructSTUtil(arr, mid + 1, se, si * 2 + 2);
        //operation dependent
        segtree[si] = arr[segtree[si * 2 + 1]] > arr[segtree[si * 2 + 2]] ? segtree[si * 2 + 1] : segtree[si * 2 + 2];
    }
    void constructST(vi arr)
    {
        segtree.resize(4 * arr.size() + 1);
        constructSTUtil(arr, 0, arr.size() - 1, 0);
    }

    int get_max_index(int ss, int se, int qs, int qe, int si)
    {
        if (ss > se || ss > qe || se < qs)
            return n;

        if (ss >= qs && se <= qe)
            return segtree[si];

        int mid = (ss + se) / 2;
        int max1 = get_max_index(ss, mid, qs, qe, 2 * si + 1), max2 = get_max_index(mid + 1, se, qs, qe, 2 * si + 2);
        return arr[max1] > arr[max2] ? max1
                                     : max2;
    }
    int getMax(int n, int qs, int qe)
    {
        return get_max_index(0, n - 1, qs, qe, 0);
    }

    void make(int l, int r, int dep)
    {
        if (l >= 0 && r < n)
        {
            int m = l;
            for (size_t i = l; i <= r; i++)
            {
                if (arr[i] > arr[m])
                    m = i;
            }

            d[m] = dep + 1;
            if (m != l)
                make(l, m - 1, dep + 1);
            if (m != r)
                make(m + 1, r, dep + 1);
        }
    }

    void solve()
    {
        cin >> n;
        arr.resize(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        constructST(arr);
        arr.resize(n + 1);
        arr[n] = INT_MIN;
        d.resize(n);
        make(0, n - 1, -1);
        for (size_t i = 0; i < d.size(); i++)
        {
            cout << d[i] << " ";
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