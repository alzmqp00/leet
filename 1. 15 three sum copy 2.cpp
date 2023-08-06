#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        multimap<int, bool> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m.insert({nums[i], 1});
        }
        auto sta = m.begin();
        auto sta2 = m.begin();
        auto end = m.end();
        end--;
        auto end2 = end;
        vector<vector<int>> res;
        int target;
        while (sta2 != end2)
        {
            target = -(sta2->first);
            sta = sta2;
            sta++;
            while (sta != end)
            {
                // 3 3 t:6
                if (sta == sta2)
                    sta++;
                else if (sta2 == end)
                    end--;
                else if (sta->first + end->first == target)
                {   
                    res.push_back({sta2->first, sta->first, end->first});
                    break;
                }

                else if (sta->first + end->first < target)
                {
                    sta++;
                }
                else
                {
                    end--;
                }
            }
            sta2++;
            end = end2;
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