#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long res = INT64_MIN;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // bool findnum = 0;
            sum += nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum += nums[j];
                if (abs(nums[i] - nums[j]) == k)
                {
                    // findnum = 1;
                    res = max(res, sum);
                }
            }
            sum = 0;
        }
        if (res == INT64_MIN)
            return 0;
        return res;
    }
};