#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums.size() < 3)
        {
            return res;
        }

        set<int> s;
        int left = 0;
        int right = nums.size() - 1;
        int target;
        bool state;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            if (nums[i] > 0)
            {
                break;
            }
            target = -nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while (left != right)
            { //[3,0,-2,-1,1,2] //-2 -1 0 2 3 3 [[-2,-1,3],[-2,0,2]]
                state = (s.count(nums[left]) || s.count(nums[right]));
                if (nums[left] + nums[right] == target && !state)
                {
                    s.insert(nums[left]);
                    s.insert(nums[right]);
                    res.push_back({nums[i], nums[left], nums[right]});
                }
                else if (nums[left] + nums[right] > target)
                    right--;
                else
                    left++;
            }
            s.clear();
        }
        return res;
    }
};
/*输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。*/