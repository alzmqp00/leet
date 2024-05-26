#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector < vector<char> row();
        vector<set<char>> col(9);
        vector<set<char>> block(3);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    auto it = row.insert(board[i][j]);
                    if (!it.second)
                        return 0;
                    auto it1 = col[j].insert(board[i][j]);
                    if (!it1.second)
                        return 0;
                    auto it2 = block[j / 3].insert(board[i][j]);
                    if (!it2.second)
                        return 0;
                }
            }
            if (i == 5 || i == 2)
            {
                block[0].clear();
                block[1].clear();
                block[2].clear();
            }
            row.clear();
        }
        return 1;
    }
};