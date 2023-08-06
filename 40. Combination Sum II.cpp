#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    map<int, int> m;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        for (auto x : candidates)
        {
            m[x]++;
        }
        vector<int> res1;
        back(candidates, target, res1, 0);
        return res;
    }
    void back(vector<int> &candidates, int target, vector<int> res1, int startindex)
    { /*输入：candidates = [2,3,6,7], target = 7
    输出：[[2,2,3],[7]]*/

        for (int i = startindex; i < candidates.size() && target >= candidates[startindex]; i++)
        {
            if (i > startindex && candidates[i - 1] == candidates[i])
                continue;
            /* if (!m[candidates[i]])
             {
                 continue;
             }*/
            target -= candidates[i];
            m[candidates[i]]--;
            res1.push_back(candidates[i]);
            if (target == 0)
            {
                res.push_back(res1);
                return;
            }
            else if (target > 0)
            {
                // back(candidates, target, res1, i);
                back(candidates, target, res1, i + 1);
            }
            m[candidates[i]]++;
            res1.pop_back();
            target += candidates[i];
        }
    }
};
