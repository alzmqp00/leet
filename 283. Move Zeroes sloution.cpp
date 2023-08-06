#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    { // 001
        // 0013500023001200 1003500023001200
        // 000013500023001200
        int firstzero = 0;
        int nonzero = 0;
        int n = nums.size();
        while (nonzero < n)
        {
            if (nums[nonzero] != 0)
            {
                swap(nums[nonzero], nums[firstzero++]);
            }
            nonzero++;
        }
    }
};