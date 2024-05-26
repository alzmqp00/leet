#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    { //"bbbab"
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        // i~j的最常回文序列的長度

        // i~i必為1
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = 1;
        }

        // 因為狀態轉移式是有關i+1和j-1 所以i從大到小    j從i到最大
        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                if (s[i] == s[j]) // 一樣就加上自己和自己的分身
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                /*   // j-i打成i-j==
                   //長度小於2 並且不相等的話必為1
                   else if (j - i <= 1)
                   {
                       dp[i][j] = 1;
                   }*/

                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][s.length() - 1];
    }
};