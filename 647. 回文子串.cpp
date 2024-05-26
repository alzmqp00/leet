#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

        // i~j是否為回文
        int res = 0;

        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = 1;
        }

        res += s.length(); // 長度為1個情況
        // 斜向 但是不一定要這樣寫用之前單純的  要倒着遍历，j 要正着遍历。 也是可以的
        for (int l = 2; l <= s.length(); l++)
        {
            for (int i = 0; i <= s.length() - l; i++)
            {
                int j = i + (l - 1);
                if (s[i] == s[j] && (dp[i + 1][j - 1] || j - i == 1))
                {
                    dp[i][j] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};