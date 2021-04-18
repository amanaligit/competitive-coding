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
    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        if (i <= 0)
            return -1;
        return (i - 1) / 2;
    }
    void solve()
    {
        int n, m;
        cin >> n >> m;
        int l = pow(2, n);
        vector<pair<int, bool>> tree(2 * l - 1);
        int k;
        for (size_t i = 0; i < l; i++)
        {
            cin >> k;
            tree[tree.size() - l + i] = make_pair(k, false);
        }
        for (int i = tree.size() - l - 1; i >= 0; i--)
        {
            if (tree[leftChild(i)].second == false)
            {

                tree[i].first = tree[leftChild(i)].first | tree[rightChild(i)].first;
                tree[i].second = true;
            }
            else
            {
                tree[i].first = tree[leftChild(i)].first ^ tree[rightChild(i)].first;
                tree[i].second = false;
            }
        }

        for (size_t i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            int node = parent(tree.size() - l + a - 1);
            tree[tree.size() - l + a - 1].first = b;
            while (node >= 0)
            {
                if (tree[leftChild(node)].second == false)
                {
                    tree[node].first = tree[leftChild(node)].first | tree[rightChild(node)].first;
                }
                else
                {
                    tree[node].first = tree[leftChild(node)].first ^ tree[rightChild(node)].first;
                }
                node = parent(node);
            }
            cout << tree[0].first << endl;
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