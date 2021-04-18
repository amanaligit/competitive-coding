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
        vi num;
        vi nodd(s.size() + 1, 0);
        for (size_t i = 0; i < s.size(); i++)
        {
            num.push_back(s[i] - '0');
            nodd[i + 1] = (s[i] - '0') % 2 ? s[i] - '0' : nodd[i];
            if ((s[i] - '0') % 8 == 0)
            {
                cout << "YES" << endl;
                cout << s[i] - '0' << endl;
                return;
            }
        }
        if (num.size() > 1)
        {
            for (size_t i = 0; i < num.size(); i++)
            {
                for (size_t j = i + 1; j < num.size(); j++)
                {
                    int temp = num[i] * 10 + num[j];
                    if (temp % 8 == 0)
                    {
                        cout << "YES" << endl;
                        cout << temp << endl;
                        return;
                    }
                    else if (((temp + 4) % 8 == 0 && nodd[i]))
                    {
                        cout << "YES" << endl;
                        cout << nodd[i] << temp << endl;
                        return;
                    }
                }
            }
        }
        cout << "NO" << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}