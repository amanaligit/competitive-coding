/*
 * @lc app=leetcode id=1654 lang=cpp
 *
 * [1654] Minimum Jumps to Reach Home
 *
 * https://leetcode.com/problems/minimum-jumps-to-reach-home/description/
 *
 * algorithms
 * Medium (25.14%)
 * Likes:    270
 * Dislikes: 70
 * Total Accepted:    8.1K
 * Total Submissions: 32.7K
 * Testcase Example:  '[14,4,18,1,15]\n3\n15\n9'
 *
 * A certain bug's home is on the x-axis at position x. Help them get there
 * from position 0.
 * 
 * The bug jumps according to the following rules:
 * 
 * 
 * It can jump exactly a positions forward (to the right).
 * It can jump exactly b positions backward (to the left).
 * It cannot jump backward twice in a row.
 * It cannot jump to any forbidden positions.
 * 
 * 
 * The bug may jump forward beyond its home, but it cannot jump to positions
 * numbered with negative integers.
 * 
 * Given an array of integers forbidden, where forbidden[i] means that the bug
 * cannot jump to the position forbidden[i], and integers a, b, and x, return
 * the minimum number of jumps needed for the bug to reach its home. If there
 * is no possible sequence of jumps that lands the bug on position x, return
 * -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
 * Output: 3
 * Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
 * Output: 2
 * Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7)
 * will get the bug home.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= forbidden.length <= 1000
 * 1 <= a, b, forbidden[i] <= 2000
 * 0 <= x <= 2000
 * All the elements in forbidden are distinct.
 * Position x is not forbidden.
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
typedef vector<bool> vb;
typedef vector<vb> vvb;

class Solution
{
public:
    unordered_set<int> fb;
    int a;
    int b;
    int maxx;
    // vb visited;
    vector<vi> dp;
    int rec(int x, bool back)
    {
        if (x == maxx)
            return 0;
        if ((fb.find(x) != fb.end()) || x < 0 || (x > 6000))
            return 1e9;
        if (dp[x][back] != -2)
            return dp[x][back];
        int forward = 0;
        // either go forward
        dp[x][back] = 1 + rec(x + a, 0);
        //go backward but cannot go consecutively 2 times
        if (!back)
        {
            dp[x][back] = min(dp[x][back], 1 + rec(x - b, 1));
        }

        return dp[x][back];
    }
    int minimumJumps(vector<int> &forbidden, int aa, int bb, int x)
    {
        a = aa;
        b = bb;
        maxx = x;
        for (auto f : forbidden)
            fb.insert(f);
        dp.resize(7001, vi(2, -2));
        // visited.resize(x + 1, 0);
        return rec(0, 0) > 1e9 ? -1 : rec(0, 0);
    }
};
// @lc code=end
