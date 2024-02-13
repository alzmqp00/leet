#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
    void backtrack(vector<string> &board, int row)
    {
        if (row == board.size()) // n
        {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++)
        {
            if (!isVaild(board, row, col))
                continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    bool isVaild(vector<string> &board, int row, int col)
    { // 不須檢查橫的

        // 檢查直的 超過row的直行 一定是空的 所以不需檢查
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return 0;
        }
        // 檢查左上和右上 (左下和右下不用)

        // 右上
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q')
                return 0;
        }
        // 左上
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return 0;
        }
        return 1;
    }
};