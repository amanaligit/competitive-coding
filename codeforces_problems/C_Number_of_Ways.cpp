#include <vector>
#include <unordered_map>
using namespace std;
#include <unordered_set>
#include <iostream>
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
const int N = 2e6 + 13;
//=======================

//=======================

class Solution
{
    vector<int> arr;

public:
    void solve()
    {
        int n;
        cin >> n;
        ll total = 0;
        for (size_t i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
            total += temp;
        }
        if (total % 3 == 0)
        {
            vector<bool> is_corrent_sum(n, false);
            ll suffix = 0;
            for (int i = arr.size() - 1; i >= 0; i--)
            {
                suffix = suffix + arr[i];
                if (suffix == total / 3)
                    is_corrent_sum[i] = true;
            }
            vector<int> sum(n + 1, 0);
            for (int i = arr.size() - 1; i >= 0; i--)
            {
                sum[i] = sum[i + 1] + is_corrent_sum[i];
            }

            ll count = 0;
            ll sum1 = 0;

            for (size_t i = 0; i < arr.size() - 2; i++)
            {
                sum1 += arr[i];
                if (sum1 == total / 3)
                {
                    count += sum[i + 2];
                }
            }

            cout << count << endl;
        }
        else
        {
            cout << 0 << endl;
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