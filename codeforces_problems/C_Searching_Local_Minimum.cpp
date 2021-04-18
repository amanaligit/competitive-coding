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
    void bs(int l, int r)
    {
        if (l == r)
        {
            cout << "! " << r << endl;
            cout.flush();
        }
        else
        {
            int m = (l + r) / 2;
            int a1, a2;
            cout << "? " << m << endl;
            cout.flush();
            cin >> a1;
            cout << "? " << m + 1 << endl;
            cout.flush();
            cin >> a2;
            if (a1 > a2)
                bs(m + 1, r);
            else
                bs(l, m);
        }
    }
    void solve()
    {
        int l, r;
        int n;
        cin >> n;
        r = n;
        l = 1;
        bs(l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}