#include <bits/stdc++.h>
using namespace std;
// 最麻煩的就是索引
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;

        res.push_back({1});
        if (numRows == 1)
            return res;
        // 第0行只有一個1 上面加好了 不用從0
        for (int i = 1; i < numRows; i++)
        {
            vector<int> temp;
            // j < (幾次循環) 由於i是索引(從0開始) 所以次數是i+1
            for (int j = 0; j < i + 1; j++)
            { // 頭尾
                if ((j - 1 >= 0) && (j != i))
                {
                    temp.push_back(res[i - 1][j] + res[i - 1][j - 1]);
                }
                else
                    temp.push_back(1);
            }
            res.push_back(temp);
        }
        return res;
    }
};