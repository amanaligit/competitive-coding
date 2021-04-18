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
typedef vector<ll> vl;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================

vi tree, lazy;

void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != 0)
    {
        //operation
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            //operation
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    if (ss > se || ss > ue || se < us)
        return;

    if (ss >= us && se <= ue)
    {
        tree[si] += (se - ss + 1) * diff;
        if (ss != se)
        {
            //operation
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }
    int mid = (ss + se) / 2;
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
    //operation
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void updateRange(int n, int us, int ue, int diff)
{
    updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

void constructSTUtil(vi arr, int ss, int se, int si)
{
    if (ss > se)
        return;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;
    constructSTUtil(arr, ss, mid, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, si * 2 + 2);
    //operation dependent
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void update(int qi, int ss, int se, int si, int diff)
{
    if (ss == se)
    {
        tree[si] += diff;
        return;
    }
    int mid = (ss + se) / 2;
    if (qi <= mid)
    {
        update(qi, ss, mid, si, diff);
    }
    else
        update(qi, mid + 1, se, si, diff);
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void constructST(vi arr)
{
    lazy.resize(4 * arr.size());
    tree.resize(4 * arr.size());
    constructSTUtil(arr, 0, arr.size() - 1, 0);
}

int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe)
        return tree[si];

    int mid = (ss + se) / 2;
    return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}
int getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(0, n - 1, qs, qe, 0);
}