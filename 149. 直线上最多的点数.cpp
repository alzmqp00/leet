#include "bits/stdc++.h"
using namespace std;
/*對於一個點 去尋找其他除了自身以外的所有點的斜率
如果發現有十個點有一樣的斜率 代表他們在同一條直線上(共11個點)*/
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int res = 0;
        vector<unordered_map<double, int>> slopee(points.size());
        // 代表第i個點 遍歷其他所有點後 用斜率當key 該斜率出現的次數當value
        // 如果發現slopee[i][m]=10 代表在第i個點 有10個點連到i的斜率是m
        // 這11點一定在同一條直線

        // 對於一個點 去尋找其他除了自身以外的所有點的斜率
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                double m;
                if (points[i][0] - points[j][0] == 0)
                    m = INFINITY;
                else
                    m = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                slopee[i][m]++;
                res = max(res, slopee[i][m]);
            }
        }
        //+1 for itself
        return res + 1;
    }
};
/*浮点数类型可能因为精度不够而无法足够精确地表示每一个斜率
因此我们需要换一种方法来记录斜率。*/