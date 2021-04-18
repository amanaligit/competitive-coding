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
        unordered_set<int> o;
        unordered_set<int> z;
        int n;
        cin >> n;
        vi pos(n);
        string s;
        cin >> s;
        int count = 1;
        for (size_t i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == '1')
            {
                if (!z.empty())
                {
                    int temp = *z.begin();
                    z.erase(temp);
                    o.insert(temp);
                    pos[i] = temp;
                }
                else
                {
                    o.insert(count);
                    pos[i] = count++;
                }
            }
            else
            {
                if (!o.empty())
                {
                    int temp = *o.begin();
                    o.erase(temp);
                    z.insert(temp);
                    pos[i] = temp;
                }
                else
                {
                    z.insert(count);
                    pos[i] = count++;
                }
            }
        }
        cout << count - 1 << endl;
        for (auto p : pos)
        {
            cout << p << " ";
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