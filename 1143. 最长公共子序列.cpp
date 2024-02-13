#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        // dp[i][j]代表的是 text1[i-1]和text2[j-1]的最常公共子字串
        // 因為[0][j]或[i][0] 代表的是一邊是取的是空字串 並不是代表從索引值的0開始
        // 所以全部要往後移一格
        for (int i = 1; i <= text1.length(); i++)
        {
            for (int j = 1; j <= text2.length(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    // dp[i-1][j-1](兩個都沒有在lcs中 必定會小於上面兩個 因為被包含)
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};