// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (30.68%)
 * Likes:    10429
 * Dislikes: 677
 * Total Accepted:    1.3M
 * Total Submissions: 4.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a"
 * Output: "a"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "ac"
 * Output: "a"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters (lower-case and/or upper-case),
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
    string longestPalindrome(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
        for (size_t i = 0; i < s.size(); i++)
        {
            dp[i][0] = 1;
        }

        int b = 0, n = 0;
        for (size_t j = 1; j < s.size(); j++)
        {
            for (size_t i = 0; i < s.size(); i++)
            {
                if (i + j >= s.size())
                    break;
                if (j == 1 || dp[i + 1][j - 2])
                {
                    dp[i][j] = s[i] == s[i + j];
                    if (dp[i][j] && j > n)
                    {
                        b = i;
                        n = j;
                    }
                }
            }
        }
        return s.substr(b, n + 1);
    }
};
// @lc code=end
