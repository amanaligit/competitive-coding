#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maxPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY skillLevel
 *  2. INTEGER minDiff
 */

int maxPairs(vector<int> a, int minDiff)
{
    if (minDiff == 0)
        return a.size() / 2;
    sort(a.begin(), a.end());
    unordered_set<int> s;
    int i = 0;
    int j = 1;
    int ans = 0;
    while (j < a.size())
    {
        while (s.find(i) != s.end())
            i++;
        while (i >= j && j + 1 < a.size())
            j++;
        if (a[j] - a[i] >= minDiff)
        {
            ans++;
            s.insert(j);
            i++;
            j++;
            continue;
        }
        while (j + 1 < a.size() && a[j] - a[i] < minDiff)
            j++;
        if (a[j] - a[i] >= minDiff)
        {
            s.insert(j);
            ans++;
        }
        i++;
        j++;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << maxPairs(a, k) << endl;
}