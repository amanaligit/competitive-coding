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
using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s)
{
    s += '#';
    long ans = 0;
    pair<char, long> sq1 = make_pair(-1, -1), sq2 = make_pair(-1, -1), sq3 = make_pair(s[0], 1);
    for (size_t i = 1; i <= n; i++)
    {
        if (s[i] == sq3.F)
            sq3.S++;
        else
        {
            ans += (sq3.S * (sq3.S + 1)) / 2;
            if (sq2.S == 1 && sq1.F == sq3.F)
                ans += min(sq1.S, sq3.S);
            sq1 = sq2;
            sq2 = sq3;
            sq3 = make_pair(s[i], 1);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
