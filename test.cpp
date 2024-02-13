#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
using namespace std;
bool compare(vector<int> a, vector<int> b)
{
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}
int main()
{

    vector<vector<int>> board = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    sort(board.begin(), board.end(), compare);

    for (int i = 0; i < board.size(); i++)
    {
        cout << board[i][0] << " " << board[i][1] << endl;
    }

    return 0;
}