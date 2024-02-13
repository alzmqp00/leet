#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    { // right預設改為1
        int left = 0, right = 0;
        int minlen = INT32_MAX;
        // int sum = nums[0];
        int sum = 0;
        /*2,3,1,2,4,3]*/
        // 小魚等魚
        while (left <= right && right < nums.size())
        {
            sum += nums[right];

            while (sum >= target)
            {
                minlen = min(minlen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if (minlen == INT32_MAX)
            return 0;
        else
            return minlen;
    }
};