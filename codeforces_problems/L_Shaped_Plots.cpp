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
    ll n, k, d;

    void solve()
    {
        int r, c;
        cin >> r >> c;
        vector<vector<bool>> mat(r, vector<bool>(c));
        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                bool temp;
                cin >> temp;
                mat[i][j] = temp;
            }
        }
        ll ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!mat[i][j])
                    continue;
                if (i - 1 >= 0 && mat[i - 1][j])
                {
                    int row = i - 1;
                    int col = j;
                    while (row >= 0 && col < c)
                    {
                        if (row - 2 >= 0 && mat[row - 1][j] == 1 && mat[row - 2][j] == 1)
                            row -= 2;
                        else
                            break;
                        if (col + 1 < c && mat[i][col + 1] == 1)
                            col++;
                        else
                            break;
                        ans++;
                    }
                }
                if (i + 1 < r && mat[i + 1][j])
                {
                    int row = i + 1;
                    int col = j;
                    while (row < r && col < c)
                    {
                        if (row + 2 < r && mat[row + 1][j] == 1 && mat[row + 2][j] == 1)
                            row += 2;
                        else
                            break;
                        if (col + 1 < c && mat[i][col + 1] == 1)
                            col++;
                        else
                            break;
                        ans++;
                    }
                }
                if (i - 1 >= 0 && mat[i - 1][j])
                {
                    int row = i - 1;
                    int col = j;
                    while (row >= 0 && col >= 0)
                    {
                        if (row - 2 >= 0 && mat[row - 1][j] == 1 && mat[row - 2][j] == 1)
                            row -= 2;
                        else
                            break;
                        if (col - 1 >= 0 && mat[i][col - 1] == 1)
                            col--;
                        else
                            break;
                        ans++;
                    }
                }
                if (i + 1 < r && mat[i + 1][j])
                {
                    int row = i + 1;
                    int col = j;
                    while (row < r && col >= 0)
                    {
                        if (row + 2 < r && mat[row + 1][j] == 1 && mat[row + 2][j] == 1)
                            row += 2;
                        else
                            break;
                        if (col - 1 >= 0 && mat[i][col - 1] == 1)
                            col--;
                        else
                            break;
                        ans++;
                    }
                }

                //Checking cols=================================
                if (j + 1 < c && mat[i][j + 1])
                {
                    int row = i;
                    int col = j + 1;
                    while (row >= 0 && col < c)
                    {
                        if (row - 1 >= 0 && mat[row - 1][j])
                            row--;
                        else
                            break;
                        if (col + 2 < c && mat[i][col + 1] && mat[i][col + 2])
                            col += 2;
                        else
                            break;
                        ans++;
                    }
                }
                if (j + 1 < c && mat[i][j + 1])
                {
                    int row = i;
                    int col = j + 1;
                    while (row < r && col < c)
                    {
                        if (row + 1 < r && mat[row + 1][j])
                            row++;
                        else
                            break;
                        if (col + 2 < c && mat[i][col + 1] && mat[i][col + 2])
                            col += 2;
                        else
                            break;
                        ans++;
                    }
                }
                if (j - 1 >= 0 && mat[i][j - 1])
                {
                    int row = i;
                    int col = j - 1;
                    while (row >= 0 && col >= 0)
                    {
                        if (row - 1 >= 0 && mat[row - 1][j])
                            row--;
                        else
                            break;
                        if (col - 2 >= 0 && mat[i][col - 1] && mat[i][col - 2])
                            col -= 2;
                        else
                            break;
                        ans++;
                    }
                }
                if (j - 1 >= 0 && mat[i][j - 1])
                {
                    int row = i;
                    int col = j - 1;
                    while (row < r && col >= 0)
                    {
                        if (row + 1 < r && mat[row + 1][j])
                            row++;
                        else
                            break;
                        if (col - 2 >= 0 && mat[i][col - 1] && mat[i][col - 2])
                            col -= 2;
                        else
                            break;
                        ans++;
                    }
                }
            }
        }

        cout << ans << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int temp = t;
    while (t--)
    {
        Solution sol;
        cout << "Case #" << temp - t << ": ";
        sol.solve();
    }
    return 0;
}