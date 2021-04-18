#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        vector <int> prefix = {0};

        if (nums.size() < 2)
            return false;

        if (k == 0)
        {
            return findZeroes(nums);
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            prefix.push_back(nums[i]+prefix[i]);
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 1; j < nums.size() - i; j++)
            {

                if((prefix[i+j+1]-prefix[i])%k==0) return true;
            }
        }
        return false;
    }

    bool findZeroes(vector<int> &nums)
    {
        int lenz = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                lenz = 0;
            else
                lenz++;
        }
        return lenz >= 2;
    }
};