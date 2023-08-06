#include <bits/stdc++.h>
using namespace std;
//用set去重 效率低下
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;
    set<vector<int>> s;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        dfs(nums, 0, 0);
        return res;
    }
    void dfs(vector<int> &nums, int index, int layer)
    {

        if (layer == nums.size())
        {

            res.push_back(temp);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == -11)
                    continue;

                temp.push_back(nums[i]);

                int temp1;
                temp1 = nums[i];
                nums[i] = -11;
                auto it = s.insert(temp);
                if (it.second != false)
                {
                    dfs(nums, i + 1, layer + 1);
                }
                nums[i] = temp1;
                temp.pop_back();
            }
        }
    }
};