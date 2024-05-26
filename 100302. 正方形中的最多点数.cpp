#include "bits/stdc++.h";
using namespace std;
class Solution
{
public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        int cnt = 0;
        multimap<int, char> m; // 我忘記用multimap...

        for (int i = 0; i < s.length(); i++)
        { // 算地i點距離中心的距離 取x y絕對值較大的那個
            int distance = (max(abs(points[i][0]), abs(points[i][1])));
            // 地i點會在 中心點在0邊長為distance的正方形的邊上
            m.insert({distance, s[i]});
            // 距離中心點近到遠排列
        }
        set<char> se; // 去重
        int predis = INT32_MIN;
        int layercnt = 1; // 計算在某一特定邊長/2上共有幾個點 因為若發現有重複標籤 整層都要檢調
        // ex 1,1 -1,1 1,-1 標籤:aba 當獨到第三個點十 發現重複 代表在正方形邊長/2=(1)時 加入的點都要刪去
        // 這邊是-3
        for (auto point : m)
        {
            // 查重
            if (!(se.count(point.second)))
            {
                se.insert(point.second);
                cnt++;
                // 判斷有無連續
                if (predis == point.first)
                    layercnt++; // 有->這層的計數+1
                else
                    layercnt = 1;
                predis = point.first;
            }
            else
            { // 第一個重複的標籤出現

                // 如果出現重複時 要檢調這層的技術
                if (predis == point.first)
                    cnt -= layercnt;
                else // 代表他是新的一層的第一個 ex 1 1 1 1 2 2出現標籤重複
                    // 但這層只有一個2 並且沒有被cnt算入 因為直接進入了else
                    return cnt;
                break;
            }
        }
        return cnt;
    }
};
