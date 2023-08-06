#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> res;
    string temp = "";
    void dfs(int n, int left = 0, int right = 0)
    {

        if (right == n && left == n)
        {
            res.push_back(temp);
            return;
        }

        else
        { //((
            if (left <= right)
            {
                temp += '(';
                dfs(n, left + 1, right);
                temp.pop_back();
            }
            else
            {
                if (left != n)
                {
                    temp += '(';
                    dfs(n, left + 1, right);
                    temp.pop_back();
                }
                if (right != n)
                {
                    temp += ')';
                    dfs(n, left, right + 1);
                    temp.pop_back();
                }
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        dfs(n, 0, 0);
        return res;
    }
};

int main()
{
    Solution a;
    vector<string> s = a.generateParenthesis(1);

    for (auto x : s)
    {
        cout << x << " ";
    }
}
// 1 2 3
// 1 2 5