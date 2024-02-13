#include <bits/stdc++.h>
using namespace std;
// grid[m][n] = '-1';不能這樣寫 char 沒有-1
class Solution
{
public:
    bool find = 0;
    void dfs(vector<vector<char>> &grid, int m, int n)
    {
        // static int c = 0;
        // cout << ++c << " ";
        // grid[m][n] = '-1';

        if (grid[m][n] == '1')
        {
            grid[m][n] = '*';
            cout << m << " " << n << "      ";
            find = 1;

            if (m + 1 < grid.size() && grid[m + 1][n] == '1')
                dfs(grid, m + 1, n);
            if (n + 1 < grid[0].size() && grid[m][n + 1] == '1')
                dfs(grid, m, n + 1);
            if (m - 1 > 0 && grid[m - 1][n] == '1')
                dfs(grid, m - 1, n);
            if (n - 1 > 0 && grid[m][n - 1] == '1')
                dfs(grid, m, n - 1);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {

                dfs(grid, i, j);
                if (find)
                    res++;
                find = 0;
            }
        }
        return res;
    }
};
/*int main()
{

   system("pause");
   return 0;
}*/
