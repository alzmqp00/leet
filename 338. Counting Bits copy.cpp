#include <bits/stdc++.h>
using namespace std;
/*[0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,1,2,2,3,2,3,3,4,2]
__builtin_popcount
0,1,12,1223,12232334,1223233423343445*/
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        res.push_back(0);
        if (n == 0)
            return res;
        res.push_back(1);
        int i = 1;
        int c = 1; // 紀錄當前二的倍數
        vector<int> temp{1};
        vector<int> temp2;
        while (i != n)
        {
            for (int j = 0; j < c; j++)
            {
                // cout << i << " ";
                res.push_back(temp[j]);
                i++;
                if (i == n)
                    break;
            }
            if (i == n)
                break;
            temp2.insert(temp2.end(), temp.begin(), temp.end());
            for (int j = 0; j < c; j++)
            {
                // cout << i << " ";
                temp[j]++;
                res.push_back(temp[j]);
                i++;
                if (i == n)
                    break;
            }

            temp2.insert(temp2.end(), temp.begin(), temp.end());
            c *= 2;
            temp = temp2;
            temp2.clear();
        }
        return res;
    }
};
int main()
{
    Solution a;
    vector<int> res = a.countBits(10);
    for (auto x : res)
    {
        cout << x << " ";
    }
}