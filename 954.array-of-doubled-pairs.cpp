// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem954.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start
class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        map<int, int> s;
        for (auto a : arr)
            s[a]++;
        while (s.size() && s.rbegin()->first > 0)
        {
            int top = s.rbegin()->first;
            if (s[top] == 1)
                s.erase(top);
            else
                s[top]--;

            if (top % 2 || s.find(top / 2) == s.end())
                return false;
            else
            {
                int k = top / 2;
                if (s[k] == 1)
                    s.erase(k);
                else
                    s[k]--;
            }
        }

        while (s.size())
        {
            int top = s.begin()->first;
            if (s[top] == 1)
                s.erase(top);
            else
                s[top]--;

            if (top % 2 || s.find(top / 2) == s.end())
                return false;
            else
            {
                int k = top / 2;
                if (s[k] == 1)
                    s.erase(k);
                else
                    s[k]--;
            }
        }

        return true;
    }
};
// @lc code=end
