#include <bits/stdc++.h>
using namespace std;
/*执行用时分布
96
ms
击败
16.64%
使用 C++ 的用户
消耗内存分布
19.19
MB
击败
5.01%
使用 C++ 的用户*/
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int len = INT32_MAX;
        vector<int> dp(nums.size(), INT32_MAX);
        // 離終點的最小距離 求起點到終點的最小距離
        dp[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            for (int j = nums[i]; j > 0; j--)
            {
                if (i + j >= nums.size() - 1)
                {
                    dp[i] = 1;
                    break; // 不確定
                } // dp[i+j]!=INT32_MAX和nums[i+j]==0 一樣 如果nums[i+j]==0 代表經過此點的路無法到達 所以dp[i]會是INT32_MAX
                else if (dp[i + j] != INT32_MAX)
                {
                    dp[i] = min(dp[i], dp[i + j] + 1);
                }
            }
        }
        return dp[0];
    }
};