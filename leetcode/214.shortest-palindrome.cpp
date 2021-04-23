// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (30.80%)
 * Likes:    1598
 * Dislikes: 151
 * Total Accepted:    114.6K
 * Total Submissions: 372.2K
 * Testcase Example:  '"aacecaaa"'
 *
 * You are given a string s. You can convert s to a palindrome by adding
 * characters in front of it.
 * 
 * Return the shortest palindrome you can find by performing this
 * transformation.
 * 
 * 
 * Example 1:
 * Input: s = "aacecaaa"
 * Output: "aaacecaaa"
 * Example 2:
 * Input: s = "abcd"
 * Output: "dcbabcd"
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of lowercase English letters only.
 * 
 * 
 */

// @lc code=start
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
ll mod(ll value)
{
    ll m = value % MOD;
    if (m < 0)
        m += MOD;
    return m;
}
//=======================

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        int st = 1;
        for (int i = s.size() / 2 + 1; i >= 1; i--)
        {
            int k = 1;
            while (i - k >= 0 && i + k < s.size() && s[i + k] == s[i - k])
                k++;
            k--;
            if (i - k == 0)
            {
                st = max(i + k + 1, st);
                break;
            }
            if (s[i] == s[i - 1])
            {
                k = 1;
                while (i - k - 1 >= 0 && i + k < s.size() && s[i + k] == s[i - k - 1])
                    k++;
                k--;
                if (i - k - 1 == 0)
                {
                    st = max(st, i + k + 1);
                    break;
                }
            }
        }
        string ans = "", a = "";
        a = s.substr(st, s.size());
        for (int i = a.size() - 1; i >= 0; i--)
<<<<<<< HEAD
            ans += a[i];
        == == == =
        {
            ans += a[i];
    }
>>>>>>> fbf0920622fe2fc70e5cfac01be440f866f0b146
    ans += s;
    return ans;
}
}
;
// @lc code=end
