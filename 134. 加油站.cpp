#include <bits/stdc++.h>
using namespace std;
/*
可以兩個迴圈


*/
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int sum = 0; // 用來記錄總和 判斷有沒有解
        int staindex = 0, maxstaindex = 0;
        int contisum = 0; // 連續和
        int maxInterval = INT32_MIN;
        int precontisum = 0;
        /*有點像是 最大連續子陣列
         maxInterval表示油箱最多可以充到多少(蓄力的概念)
         maxstaindex是maxInterval的起始位置
         如果找到一個區間 他可以累績最多的油 那這個區間的起始位置就是解(無解的情況由sum判斷)
         */
        for (int i = 0; i < gas.size(); i++)
        {

            contisum += gas[i] - cost[i]; // 這站可以得到的油 +、-
            // 代表從這開始可以得到正的油 開始計算區間
            if (precontisum < 0 && contisum >= 0)
            {
                staindex = i;
            }
            //<0 拋棄
            if (contisum < 0)
            {
                precontisum = contisum; // 要先記錄再拋棄為0
                contisum = 0;
            }
            else
                precontisum = contisum;

            if (contisum > maxInterval)
            {
                maxstaindex = staindex;
                maxInterval = contisum;
            }
            sum += gas[i] - cost[i];
        }

        // 從後面記數到前面
        for (int i = 0; i < gas.size(); i++)
        {
            /*if (gas[i] - cost[i] < 0)
                 break;
                 -1 3 -4 2
                 需要2 -1 3才能集滿4 所以不能讓他break;
                 */
            contisum += gas[i] - cost[i];
            if (contisum < 0)
                break;
            if (contisum > maxInterval)
            {
                maxstaindex = staindex;
            }
        }

        if (sum < 0)
            return -1;
        else
            return maxstaindex;
    }
};