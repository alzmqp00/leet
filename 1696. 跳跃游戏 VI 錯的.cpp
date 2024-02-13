#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int res = 0;
        int find_negative = INT32_MIN;
        bool find_positive = 0;
        res += nums[0];
        for (int i = 1; i < nums.size(); i += k)
        {
            for (int j = i; j < nums.size() && j < i + k; j++)
            {
                if (nums[j] > 0)
                {
                    res += nums[j];
                    find_positive = 1;
                }

                else
                {
                    find_negative = max(find_negative, nums[j]);
                }
            }
            if (!find_positive)
                res += find_negative;

            find_negative = INT32_MIN;
            find_positive = 0;
        }
        return res;
    }
};