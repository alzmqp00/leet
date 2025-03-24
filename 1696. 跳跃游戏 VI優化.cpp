#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = INT32_MIN; /*
             for (int j = 1; j <= k; j++)
             { // 對於每一個i都往回k步找最大值
                 if (i - j >= 0)
                     dp[i] = max(dp[i - j], dp[i]);
             }*/

            dp[i] += nums[i];
        }
        return dp.back();
    }
};