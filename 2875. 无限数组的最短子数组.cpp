// https://leetcode.cn/contest/weekly-contest-365/problems/minimum-size-subarray-in-infinite-array/
#include "bits/stdc++.h"
//沒寫出來
using namespace std;
class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        int sum = 0;
        for (auto num : nums)
            sum += num;
        int res = 0;
        res += (target / sum) * nums.size();
        target %= sum;
        int left = 0;
        int right = 0;
        // target -= nums[0];
        while (right < nums.size())
        {
            target -= nums[right];
            while (target < 0)
            {
                target += nums[left++];
            }
            if (target == 0)
                return res + right - left + 1;
            right++;
        }
        return -1;
    }
};