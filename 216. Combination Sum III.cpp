#include <bits/stdc++.h>
using namespace std;
// 1.我沒看到題目說只能用1~9的數字
// 2.其實根本不需要加上 || startnum == 10之類的 因為for裡面已經有限制i <= 9 所以當下一層i==10的時候for不會被執行
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;
    int sum = 0;
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (k > n)
            return {};
        dfs(k, n, 1, 0);
        return res;
    }
    void dfs(int k, int n, int startnum = 1, int depth = 0)
    {
        if (sum > n)
            return;

        if (depth == k)
        {
            if (sum == n)
                res.push_back(temp);
            return;
        }
        else
        {
            for (int i = startnum; i <= 9; i++)
            {
                sum += i;
                temp.push_back(i);
                dfs(k, n, i + 1, depth + 1);
                temp.pop_back();
                sum -= i;
            }
        }
    }
};