#include "bits/stdc++.h"
using namespace std;
//第 394 场周赛
class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        vector<vector<int>> hash(10, vector<int>(grid[0].size())); // 最多
        multimap<int, pair<int, int>> times;                    // 次數 數字 哪一列                            //{次數 數字}
        set<int> marked;
        int res = 0;

        for (int j = 0; j < grid[0].size(); j++)
        {
            for (int i = 0; i < grid.size(); i++)
            {
                hash[grid[i][j]][j]++;
            }
        }
        for (int j = 0; j < grid[0].size(); j++)
        {
            for (int i = 0; i < grid.size(); i++)
            {
                times.insert({hash[grid[i][j]][j], {grid[i][j], j}});
            }
        }
        vector<int> usednum(grid[0].size());

        for (auto it = times.rbegin(); it != times.rend(); it++)
        {
            if (!marked.count((it->second).second))
            {
                if (marked.count((it->second).second + 1) && usednum[(it->second.second) + 1]==it->second.first)
                {
                    continue;
                }
                if (marked.count((it->second).second - 1) && usednum[(it->second.second) - 1]==it->second.first)
                {
                    continue;
                }
               /* if((it->second).first==0)
                    res++;
                else */
                cout<<it->first<<" "<<it->first.first<<" "<<it->first.second<<endl;

                res += grid.size() - it->first;
                marked.insert(it->second.second);
                usednum[it->second.second]=it->second.first;
            }
        }
        res+=grid[0].size()-marked.size();
        return res;
    }
};

/*
590 / 658 个通过测试用例
状态：解答错误
提交时间：几秒前
最后执行的输入：
[[2,6,6,9,8,4,2,6,2,3]]
*/

/*598 / 658 个通过测试用例
状态：解答错误
提交时间：几秒前
最后执行的输入：
[[0,0,1,7,4,0],
[9,4,6,2,7,7],
[2,9,7,8,4,3],
[7,6,9,7,9,3],
[6,7,0,9,1,3],
[2,2,9,5,7,9]]
            3
            
7和4是一樣多的 在倒數第二排
因此程式可能會選擇7或4作為那一列的數字(理論上不是隨機)
選4明顯比較好 因為這樣左邊就可以用7
但是程式不知道 所以就算他有4可以選 可能也會選7 讓隔壁的被迫只能夠找下一個出現在times上的數字
導致步驟變多

(4->5 就正常了)
*/