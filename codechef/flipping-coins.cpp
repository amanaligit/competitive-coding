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
typedef vector<bool> vb;
typedef vector<vb> vvb;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================
ll mod(ll value)
{
    ll m = value % MOD;
    if (m < 0)
        m += MOD;
    return m;
}
//=======================

typedef struct node
{
    int c;
    struct node *l;
    struct node *r;
    struct node *p = nullptr;
    int ss, se;
    node(int c, int ss, int se, struct node *l, struct node *r) : c(c), ss(ss), se(se), l(l), r(r) {}
} Node;

class Solution
{
public:
    void fix(Node *root)
    {
        while (root != nullptr)
        {
            root->c = root->l->c + root->r->c;
            root = root->p;
        }
    }
    void update(Node *root1, Node *root2, int qs, int qe)
    {

        if (qs <= root1->ss && qe >= root1->se)
        {
            Node *p1 = root1->p;
            Node *p2 = root2->p;
            bool b1 = p1->l == root1;
            bool b2 = p2->l == root2;
            root1->p = p2;
            if (b2)
                p2->l = root1;
            else
                p2->r = root1;
            root2->p = p1;
            if (b1)
                p1->l = root2;
            else
                p1->r = root2;
            fix(root1->p);
            fix(root2->p);
            return;
        }

        // If segment of this node is outside the given range
        if (root1->se < qs || root1->ss > qe)
            return;

        // If a part of this segment overlaps with the given range
        update(root1->l, root2->l, qs, qe);
        update(root1->r, root2->r, qs, qe);
        return;
    }
    int getSumUtil(Node *root, int qs, int qe)
    {
        // If segment of this node is a part of given range, then return
        // the sum of the segment
        if (qs <= root->ss && qe >= root->se)
            return root->c;

        // If segment of this node is outside the given range
        if (root->se < qs || root->ss > qe)
            return 0;

        // If a part of this root->segment overlaps with the given range
        return getSumUtil(root->l, qs, qe) +
               getSumUtil(root->r, qs, qe);
    }
    Node *makeTree(int s, int e, bool bit)
    {
        if (s == e)
            return new Node(bit, s, e, nullptr, nullptr);
        int mid = (s + e) / 2;
        Node *lc = makeTree(s, mid, bit);
        Node *rc = makeTree(mid + 1, e, bit);
        Node *n = new Node(lc->c + rc->c, s, e, lc, rc);
        lc->p = n;
        rc->p = n;
        return n;
    }
    void solve()
    {
        int n, q;
        cin >> n >> q;
        Node *t1 = makeTree(1, n, 0);
        Node *t2 = makeTree(1, n, 1);
        for (size_t i = 0; i < q; i++)
        {
            int yes, qs, qe;
            cin >> yes >> qs >> qe;
            if (yes)
                cout << getSumUtil(t1, qs + 1, qe + 1) << endl;
            else
            {
                if (qs == 0 && qe == n - 1)
                {
                    swap(t1, t2);
                }
                else
                    update(t1, t2, qs + 1, qe + 1);
            }
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