#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        bool res = 0;
        back(nums, 0, dp, res);
        return res;
    }
    void back(vector<int> &nums, int index, vector<int> dp, bool &find)
    {
        if (find)
            return;
        if (index >= nums.size() - 1)
            find = 1;
        for (int j = nums[index]; j >= 1; j--)
        {
            if (index + j >= nums.size() - 1)
            {
                find = 1;
                break;
            }
            if (!(dp[j + index] == -1 || (nums[index + j] == 0)))
            {
                back(nums, index + j, dp, find);
            }
            dp[index + j] = -1;
        }
    }
};