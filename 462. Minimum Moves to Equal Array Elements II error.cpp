#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {   //中位數才是最佳解
        int res = 0;
        int avg;
        int left, right;
        sort(nums.begin(), nums.end());
        avg = (accumulate(nums.begin(), nums.end(), 0)) / nums.size();
        int midindex;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= avg)
            {
                midindex = i;
                break;
            }
        }
        // 00168 3 midindex=3
        if (midindex < nums.size() - 1 - midindex)
        { // 3<5-3
            for (auto it : nums)
            {
                res += abs(it - nums[midindex]);
            }
        }
        else if (midindex > nums.size() - 1 - midindex)
        {
            for (auto it : nums)
            {
                res += abs(it - nums[midindex - 1]);
            }
        }
        else
        {
            for (auto it : nums)
            {
                res += abs(it - avg);
            }
        }

        return res;
    }
};