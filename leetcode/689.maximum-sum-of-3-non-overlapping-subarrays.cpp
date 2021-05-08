// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 *
 * https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/
 *
 * algorithms
 * Hard (47.35%)
 * Likes:    1225
 * Dislikes: 81
 * Total Accepted:    53.7K
 * Total Submissions: 113.3K
 * Testcase Example:  '[1,2,1,2,6,7,5,1]\n2'
 *
 * Given an integer array nums and an integer k, find three non-overlapping
 * subarrays of length k with maximum sum and return them.
 * 
 * Return the result as a list of indices representing the starting position of
 * each interval (0-indexed). If there are multiple answers, return the
 * lexicographically smallest one.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,1,2,6,7,5,1], k = 2
 * Output: [0,3,5]
 * Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting
 * indices [0, 3, 5].
 * We could have also taken [2, 1], but an answer of [1, 3, 5] would be
 * lexicographically larger.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
 * Output: [0,2,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] < 2^16
 * 1 <= k <= floor(nums.length / 3)
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
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        vl pre(nums.size() + 1);
        pre[0] = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }
        vl sum3(nums.size() - k + 1);
        for (size_t i = 0; i <= nums.size() - k; i++)
        {
            sum3[i] = pre[i + k] - pre[i];
        }
        vector<pair<ll, int>> maxSum1(nums.size() - k + 1);
        maxSum1[0] = make_pair(sum3[0], 0);
        for (int i = 1; i < sum3.size(); i++)
        {
            auto temp = make_pair(sum3[i], i);
            maxSum1[i] = temp.F > maxSum1[i - 1].F ? temp : maxSum1[i - 1];
        }
        vector<pair<ll, int>> maxSum2(nums.size() - k + 1);
        maxSum2.back() = make_pair(sum3.back(), sum3.size() - 1);
        for (int i = sum3.size() - 2; i >= 0; i--)
        {
            auto temp = make_pair(sum3[i], i);
            maxSum2[i] = temp.F >= maxSum2[i + 1].F ? temp : maxSum2[i + 1];
        }
        vector<int> ans(3);
        ans[1] = k;
        ans[0] = maxSum1[0].S;
        ans[2] = maxSum2[k + k].S;
        for (size_t j = k + 1; j <= nums.size() - 2 * k; j++)
        {
            vector<int> temp(3);
            temp[1] = j;
            temp[0] = maxSum1[j - k].S;
            temp[2] = maxSum2[j + k].S;
            if (sum3[temp[0]] + sum3[temp[1]] + sum3[temp[2]] > sum3[ans[0]] + sum3[ans[1]] + sum3[ans[2]])
                ans = temp;
        }
        return ans;
    }
};
// @lc code=end
