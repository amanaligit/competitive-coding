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
        string s;
        cin >> s;
        vvi n(10);
        for (int i = 0; i < s.size(); i++)
        {
            n[s[i] - '0'].push_back(i);
        }
        int maxcount = 0;
        for (int i = 0; i < n.size(); i++)
        {
            maxcount = max(maxcount, int(n[i].size()));
            for (int j = 0; j < n.size(); j++)
            {
                if (i == j)
                    continue;
                int k = 0, l = 0, m = -1;
                int count = 0;
                while (k < n[i].size() && l < n[j].size())
                {
                    if (n[i][k] < n[j][l] && n[i][k] > m)
                    {
                        count += 2;
                        k++;
                        m = n[j][l++];
                    }
                    else if (n[i][k] < m)
                    {
                        k++;
                    }
                    else
                    {
                        l++;
                    }
                }
                maxcount = max(maxcount, count);
            }
        }
        cout << s.size() - maxcount << endl;
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