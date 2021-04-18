#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

//=======================
const int MOD = 1000000000;
const int N = 2e6 + 13, M = N;
//=======================
int modulo(int value)
{
    int mod = value % MOD;
    if (mod < 0)
        mod += MOD;
    return mod;
}
//=======================

class Solution
{
public:
    ll n, k, d;
    int i = 0;
    pii read(char ch)
    {
        int x = 0, y = 0;
        if (ch == 'S')
            y = (y + 1) % MOD;
        else if (ch == 'W')
            x = (x - 1) % MOD;
        else if (ch == 'N')
            y = (y - 1) % MOD;
        else if (ch == 'E')
            x = (x + 1) % MOD;
        else
        {
            int c = int(ch - '0');
            int x1 = 0, y1 = 0;
            getchar();
            ch = getchar();
            while (ch != ')')
            {
                pii p = read(ch);
                x1 += p.F;
                y1 += p.S;
                ch = getchar();
            }
            x = (c * x1) % MOD;
            y = (c * y1) % MOD;
        }
        return make_pair(x, y);
    }
    void solve()
    {
        int x = 0, y = 0;
        char ch;
        while ((ch = getchar()) != '\n')
        {
            if (ch == EOF)
                break;
            pii p = read(ch);
            x = modulo(x + p.F);
            y = modulo(y + p.S);
        }
        cout << x + 1 << " " << y + 1 << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    int temp = t;
    getchar();
    while (t--)
    {
        Solution sol;
        cout << "Case #" << temp - t << ": ";
        sol.solve();
    }
    return 0;
}