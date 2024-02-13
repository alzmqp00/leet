#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int cnt = 0;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {   // 33 11 3<1 and 3>
                // 判斷是不是在左上角和右下角 並且兩點可交換
                if (!(points[i][0] <= points[j][0] && points[i][1] >= points[j][1]) && !(points[j][0] <= points[i][0] && points[j][1] >= points[i][1]))
                    continue;
                cnt++; // 我原本寫這行在第三個for迴圈 這是錯誤的 因為這樣 假設我取同樣的兩個點會重複計算
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;

                    if (max(points[i][0], points[j][0]) >= points[k][0] && min(points[i][0], points[j][0]) <= points[k][0])
                        if (max(points[i][1], points[j][1]) >= points[k][1] && min(points[i][1], points[j][1]) <= points[k][1])
                        {
                            cnt--;
                            break;
                        }
                    cout << points[i][0] << " " << points[i][1] << endl;
                    cout << points[j][0] << " " << points[j][1] << endl;
                    cout << i << " " << j << "\n"
                         << endl;
                }
            }
        }

        return cnt;
    }
};