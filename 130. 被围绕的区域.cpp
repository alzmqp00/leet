#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<bool>> isnorepeat;
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &isvisited, int m, int n)
    {
        if (board[m][n] == 'O' && isvisited[m][n] != 1)
        {
            isvisited[m][n] = 1;
            if (m + 1 < board.size() && board[m + 1][n] == 'O')
                dfs(board, isvisited, m + 1, n);
            if (n + 1 < board[0].size() && board[m][n + 1] == 'O')
                dfs(board, isvisited, m, n + 1);
            if (m - 1 > 0 && board[m - 1][n] == 'O')
                dfs(board, isvisited, m - 1, n);
            if (n - 1 > 0 && board[m][n - 1] == 'O')
                dfs(board, isvisited, m, n - 1);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        isnorepeat.resize(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board[0].size(); i++)
        {
            dfs(board, isnorepeat, 0, i);
            dfs(board, isnorepeat, board.size() - 1, i);
        }
        for (int i = 1; i < board.size() - 1; i++)
        {
            dfs(board, isnorepeat, i, 0);
            dfs(board, isnorepeat, i, board[0].size() - 1);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (isnorepeat[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};
/*int main()
{

   system("pause");
   return 0;
}*/
