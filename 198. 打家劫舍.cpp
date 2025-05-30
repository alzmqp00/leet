#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0); // 偷i的的情況下的最大值
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + nums[0];
        for (int i = 3; i < nums.size(); i++)
        {
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]); // 分別是偶數最大和奇數最大
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};