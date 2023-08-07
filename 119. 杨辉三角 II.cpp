#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res;
        vector<int> temp;
        res = {1};
        if (rowIndex == 0)
            return res;
        res = {1, 1};
        if (rowIndex == 1)
            return res;
        for (int i = 2; i <= rowIndex; i++)
        {
            temp.push_back(1);
            for (int j = 0; j < i - 1; j++)
            {
                temp.push_back(res[j] + res[j + 1]);
            }
            temp.push_back(1);
            res = temp;
            temp.clear();
        }
        return res;
    }
};