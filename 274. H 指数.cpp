#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int res = 1;
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); i++)
        {
            // 前面有幾個數字(包含) i+1;
            if (citations[i] >= res)
            {
                if (citations[i] >= res)
                    return res + 1;
                else
                    return res;
            }

            res++;
        }
        return citations[0] == 0 ? 0 : citations.size();
    }
};
/*class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/h-index/solutions/869042/h-zhi-shu-by-leetcode-solution-fnhl/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/