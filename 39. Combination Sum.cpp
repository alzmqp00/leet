#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<int> res1;
        back(candidates, target, res1, 0);
        return res;
    }
    void back(vector<int> &candidates, int target, vector<int> res1, int startindex)
    { /*输入：candidates = [2,3,6,7], target = 7
    输出：[[2,2,3],[7]]*/

        for (int i = startindex; i < candidates.size(); i++)
        {
            target -= candidates[i];
            res1.push_back(candidates[i]);
            if (target == 0)
            {
                res.push_back(res1);
                return;
            }
            else if (target > 1)
            {
                back(candidates, target, res1, i);
            }

            res1.pop_back();
            target += candidates[i];
        }
    }
};
