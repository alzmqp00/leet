#include <bits/stdc++.h>
using namespace std;
// 想像是一顆八元樹 差別只是節點是一邊BFS一邊產生
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        if (target == "0000")
            return 0;
        int res = 0; // 要從0開始 從一開始會多一
        queue<string> q;
        string nextNode;
        unordered_set<string> visit;
        for (auto String : deadends)
        {
            visit.insert(String);
        }
        auto it = visit.insert("0000");
        // 有一筆測資起始點在deadends害我要加這個 如果起始點在deadends裡就return
        if (!it.second)
            return -1;
        q.push("0000");
        while (!q.empty())
        {

            int sz = q.size(); // 先儲存size 如果在for用.size size的值是會變化的
            for (int i = 0; i < sz; i++)
            { /*
              假設此時 res==3
          這個迴圈進行中時 代表
          他正從第三層的佇列中 找到應該要是第四層的元素放入佇列
          if找到了 要回傳現在的res而不是加過的
          */
                if (q.front() == target)
                    return res;
                // 相鄰8個節點 因此每次要放入8個節點
                for (int i = 0; i < 4; i++)
                {
                    nextNode = q.front();
                    if (nextNode[i] != '9')
                        nextNode[i] = nextNode[i] + 1;
                    else
                        nextNode[i] = '0';

                    if (visit.count(nextNode) == 0)
                    {
                        visit.insert(nextNode);
                        q.push(nextNode);
                    }

                    nextNode = q.front();
                    if (nextNode[i] != '0')
                        nextNode[i] = nextNode[i] - 1;
                    else
                        nextNode[i] = '9';

                    if (visit.count(nextNode) == 0)
                    {
                        visit.insert(nextNode);
                        q.push(nextNode);
                    }
                }
                q.pop();
            }
            res++;
        }
        return -1;
    }
};
