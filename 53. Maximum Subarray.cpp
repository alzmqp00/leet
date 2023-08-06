#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int cursum = 0;
        auto it = max_element(nums.begin(), nums.end());
        int max = *it;
        if(max<=0){
            return max;
        }
        int index = 0;
        while (index < nums.size())
        {
            cursum += nums[index];
            if (cursum < 0)
            {
                index++;
                cursum = 0;
            }
            else
            {
                index++;
            }
            if (cursum > max)
            {
                max = cursum;
            }
        }
        return max;
    }
};
