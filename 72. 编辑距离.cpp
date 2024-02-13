#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    { // 到i-1,j-1為止的最小編距離
        // 因為index==0表示空字串 不是字串的第一個字母 所以大小要加一
        // 可以想成是多用了一個長度去存字串的情況 或是i、j直接代表字串長度
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        // 當word2為空時 word1要變成word2的距離必定==word1的長度(每一個都選擇清除)
        for (int i = 1; i <= word1.length(); i++)
        {
            dp[i][0] = i;
        }
        // 當word1為空時 word1要變成word2的距離必定==word2的長度(每一個都選擇新增)
        for (int i = 1; i <= word2.length(); i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.length(); i++)
        {
            for (int j = 1; j <= word2.length(); j++)
            { // 做選擇 如果字母已經一樣就不需要多花一個步驟
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                { // 刪除 插入 替換
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};