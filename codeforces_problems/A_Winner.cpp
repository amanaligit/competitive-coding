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
        unordered_map<string, vector<pair<ll, int>>> scores;
        int n;
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            string name;
            int score;
            cin >> name >> score;
            if (scores[name].size())
            {
                ll ns = scores[name].back().first + score;
                scores[name].push_back(make_pair(ns, i));
            }
            else
                scores[name].push_back(make_pair(score, i));
        }
        vector<string> p;
        ll ms = 0;
        for (auto name : scores)
        {
            if (name.second.back().first > ms)
            {
                p = {};
                p.push_back(name.first);
                ms = name.second.back().first;
            }
            else if (name.second.back().first == ms)
                p.push_back(name.first);
        }
        int index = n + 1;
        string winner;
        for (auto player : p)
        {
            int i;
            for (int j = scores[player].size() - 1; j >= 0; j--)
            {
                if (scores[player][j].first >= ms)
                    i = scores[player][j].second;
            }
            if (i < index)
            {
                index = i;
                winner = player;
            }
        }

        cout << winner << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution sol;
    sol.solve();

    return 0;
}