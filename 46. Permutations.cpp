#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> permute(vector<int> &nums)
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
                dfs(nums, i + 1, layer + 1);
                nums[i] = temp1;
                temp.pop_back();
            }
        }
    }
};

/*permuteUnique*/