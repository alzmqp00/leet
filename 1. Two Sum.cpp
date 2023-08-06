#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v1;
        for (int j = 0; j < nums.size() - 1; j++)
        {
            if (nums[j] > target)
            {
                continue;
            }
            for (int i = j + 1; i < nums.size(); i++)
            {
                if (nums[j] + nums[i] == target)
                {
                    v1 = {j, i};
                    break;
                }
            }
        }

        return v1;
    }
};