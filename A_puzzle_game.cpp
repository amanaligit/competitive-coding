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
vector<vector<int>> pre = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

ll toLL(vvi state)
{
    ll ans = 0;
    for (auto s : state)
    {
        for (auto n : s)
        {
            ans = ans * 10 + n;
        }
    }
    return ans;
}

unordered_map<ll, int> len;

void bfs()
{
    // swap(pre, final);
    vvi state = pre;
    queue<vvi> q;
    q.push(state);
    len[toLL(state)] = 0;
    int c = 1;
    vector<bool> isPrime = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
    while (q.size())
    {
        int curr = q.size();
        for (int i = 0; i < curr; i++)
        {
            state = q.front();
            q.pop();
            // c++;
            // get all adjacent nodes
            // 9!
            for (size_t i = 0; i < 3; i++)
                for (size_t j = 0; j < 2; j++)
                {
                    if (isPrime[state[i][j] + state[i][j + 1]])
                    {
                        vvi temp = state;
                        swap(temp[i][j], temp[i][j + 1]);
                        if (len.find(toLL(temp)) == len.end())
                        {
                            len[toLL(temp)] = c;
                            q.push(temp);
                        }
                    }
                }
            for (size_t j = 0; j < 3; j++)
                for (size_t i = 0; i < 2; i++)
                {
                    if (isPrime[state[i][j] + state[i + 1][j]])
                    {
                        vvi temp = state;
                        swap(temp[i][j], temp[i + 1][j]);
                        if (len.find(toLL(temp)) == len.end())
                        {
                            len[toLL(temp)] = c;
                            q.push(temp);
                        }
                    }
                }
        }
        c++;
    }
    // cout << c << endl;
}

class Solution
{
public:
    int isPrime(int N)
    {
        if (N < 2 || (!(N & 1) && N != 2))
            return 0;
        for (int i = 3; i * i <= N; i += 2)
        {
            if (!(N % i))
                return 0;
        }
        return 1;
    }

    void solve()
    {
        vvi final(3, vi(3));
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                cin >> final[i][j];
            }
        }
        if (len.find(toLL(final)) == len.end())
        {
            cout << -1 << endl;
        }
        else
            cout << len[toLL(final)] << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    bfs();
    int t;
    cin >> t;
    while (t--)
    {
        Solution sol;
        sol.solve();
    }
    return 0;
}