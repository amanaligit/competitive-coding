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

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    int u = abs(r_q - n);
    int d = abs(r_q - 1);
    int l = abs(c_q - 1);
    int r = abs(c_q - n);
    int lu = min(l, u);
    int ld = min(d, l);
    int ru = min(r, u);
    int rd = min(r, d);
    for (auto o : obstacles)
    {
        if (o[1] == c_q && o[0] > r_q)
            u = min(abs(o[0] - r_q) - 1, u);
        else if (o[1] == c_q && o[0] < r_q)
            d = min(abs(o[0] - r_q) - 1, d);
        else if (o[0] == r_q && o[1] > c_q)
            r = min(abs(o[1] - c_q) - 1, r);
        else if (o[0] == r_q && o[1] < c_q)
            l = min(abs(o[1] - c_q) - 1, l);
        //diagonals
        else if (abs(o[0] - r_q) == abs(o[1] - c_q) && o[0] > r_q && o[1] > c_q)
            ru = min(abs(o[0] - r_q) - 1, ru);
        else if (abs(o[0] - r_q) == abs(o[1] - c_q) && o[0] < r_q && o[1] > c_q)
            rd = min(abs(o[1] - c_q) - 1, rd);
        else if (abs(o[0] - r_q) == abs(o[1] - c_q) && o[0] > r_q && o[1] < c_q)
            lu = min(abs(o[0] - r_q) - 1, lu);
        else if (abs(o[0] - r_q) == abs(o[1] - c_q) && o[0] < r_q && o[1] < c_q)
            ld = min(abs(o[0] - r_q) - 1, ld);
    }
    return u + d + l + r + lu + ld + ru + rd;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++)
    {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
