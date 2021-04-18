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
    int bs(vl &pre, int l, int r, int &t)
    {
        if (l >= r)
            return r;
        else
        {
            int mid = (l + r) / 2;
            if (pre[mid] - pre[t] < pre[t])
                return bs(pre, mid + 1, r, t);
            else
                return bs(pre, l, mid, t);
        }
    }

    int bs2(vl &pre, int l, int r, int &i)
    {
        if (r <= l)
            return l;
        else
        {
            int mid = ceil(((double)l + r) / 2);
            if (pre[mid] - pre[i] <= pre.back() - pre[mid])
                return bs2(pre, mid, r, i);
            else
                return bs2(pre, l, mid - 1, i);
        }
    }

    int waysToSplit(vector<int> &nums)
    {
        vl pre(nums.size());

        pre[0] = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
            pre[i] = modulo(pre[i - 1] + nums[i]);

        int i = 0;
        int l = 1;
        ll ans = 0;
        int lj = 1;
        int sj = 1;
        while (pre[i] <= pre[nums.size() - 1] / 3 && i < nums.size() - 2)
        {
            ll w = 0;
            l = bs(pre, max(i + 1, lj), nums.size() - 2, i);
            int r = bs2(pre, l, nums.size() - 2, i);
            lj = l;
            if (pre[l] - pre[i] > pre.back() - pre[l])
            {
                i++;
                continue;
            }
            w = r - l + 1;
            ans = modulo(ans + w);
            i++;
        }
        return ans;
    }
};

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
