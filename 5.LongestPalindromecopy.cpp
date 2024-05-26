#include <bits/stdc++.h>
using namespace std;
int main()
{ // dp[i][j]表示s[i]~s[j]是否為回文子串 及以i j為區間(包含 其中j>i)的子串是否為回文子串
    string s;
   cin >> s;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int left = 0, right = s.size()-1, Maxlenth = 0; // 用來記錄最長的回文子串
    // 因為會先確定情況1、2 從後往前可以保證需要用到的東西 :dp[i+1][j-1]已經確定
    // 這部分可以畫一個表格(倒三角形)來看
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = s.size() - 1; j >= i; j--)
        {
            // 情況1
            if (i == j) // 1~1、2~2、3~3、4~4、5~5、6~6、7~7、8~8、9~9...必回文
                dp[i][j] = 1;
            // 情況2 aa bb回文 ab不回文 aba abb 不回文 因此當j - i <= 2 只要確定s[i] == s[j] 就知道有沒有回文
            else if (j - i <= 2 && s[i] == s[j]) //
                dp[i][j] = 1;
            // 情況3 當s[i] == s[j] 且dp[i+1][j-1]為回文時 dp[i][j]也為回文
            //       當s[i] != s[j] 免談
            else if (i + 1<s.size() && j - 1>=0 && dp[i + 1][j - 1] && s[i] == s[j])
                dp[i][j] = 1;
            if (dp[i][j])
            {
                if (Maxlenth < j - i + 1)
                {
                    Maxlenth = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
    }
        cout << s.substr(left, right - left + 1) << endl;
    
    return 0;
}
