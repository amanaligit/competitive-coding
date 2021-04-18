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
        int len = 0;
        int ab = 0, ba = 0, a34 = 0, a5 = 0;
        char start;
        for (size_t i = 0; i < s.size(); i++)
        {
            if ((s[i] == 'A' || s[i] == 'B') && len == 0)
            {
                start = s[i];
                len++;
            }
            else if ((s[i] == 'A' && len > 0))
            {
                if (s[i - 1] == 'B')
                    len++;
                else
                {
                    if (len == 2)
                        ba++;
                    else if (len > 2 && len < 5)
                    {
                        a34++;
                    }
                    else if (len >= 5)
                    {
                        cout << "YES" << endl;
                        return;
                    }
                    len = 1;
                    start = s[i];
                }
            }
            else if ((s[i] == 'B' && len > 0))
            {
                if (s[i - 1] == 'A')
                    len++;
                else
                {
                    if (len == 2)
                        ab++;
                    else if (len > 2 && len < 5)
                    {
                        a34++;
                    }
                    else if (len >= 5)
                    {
                        cout << "YES" << endl;
                        return;
                    }
                    len = 1;
                    start = s[i];
                }
            }
            else
            {
                if (len > 0)
                {
                    if (len == 2 && start == 'A')
                        ab++;
                    else if (len == 2 && start == 'B')
                    {
                        ba++;
                    }
                    else if (len > 2 && len < 5)
                    {
                        a34++;
                    }
                    else if (len >= 5)
                    {
                        cout << "YES" << endl;
                        return;
                    }
                }
                len = 0;
            }
        }
        if (len > 0)
        {
            if (len == 2)
                start == 'A' ? ab++ : ba++;

            else if (len > 2 && len < 5)
            {
                a34++;
            }
            else if (len >= 5)
            {
                cout << "YES" << endl;
                return;
            }
        }
        if ((ab && ba) || ((ab || ba) && a34) || (a34 > 1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}