#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int dis;
        int max = 0;
        int v; // 容積
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                dis = j - i;
                v = dis * min(height[i], height[j]);
                if (v > max)
                {
                    max = v;
                }
            }
        }
        return max;
    }
};