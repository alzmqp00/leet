#include <bits/stdc++.h>
using namespace std;
// 照書上的
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
            return 0;
        int need_cnt = s1.length();
        vector<int> window(26, 0);
        vector<int> need(26, 0);
        int left = 0, right = 0;
        //"eidboaoo" "ab"
        for (int i = 0; i < s1.length(); i++)
        {
            // window[s1[i] - 'a']++;
            need[s1[i] - 'a']++;
        }
        while (right < s2.size())
        {

            if (need[s2[right] - 'a'] > 0)
            {
                window[s2[right] - 'a']++;
                // 為什麼是小於等於
                // 因為 假設你只需要2個a 但是s2="aaaaaaXXX" 則剩餘需要的最多只能-2
                // 在window裡的字母 若已經超過need 那麼繼續增加不會讓剩餘需要的字母變少
                if (window[s2[right] - 'a'] <= need[s2[right] - 'a'])
                    need_cnt--;
            }
            //  if (right - left + 1 == s1.size()) 也是可以的
            // 當視窗大小和s1一樣時 要檢查結果 如果沒有true 則繼續增加left
            while (right - left + 1 >= s1.size())
            {
                if (need_cnt == 0)
                    return 1;

                if (need[s2[left] - 'a'] > 0)
                { // 理由類似上面
                    ////在window裡的字母 若沒有小於need 那麼繼續減少不會讓剩餘需要的字母變多
                    // 想像window裡有100個a 但是need裡只有10個 從就算視窗裡的a從100->10 對於剩餘需要的數字也不會改變 a都是溢出的
                    if (window[s2[left] - 'a'] <= need[s2[left] - 'a'])
                        need_cnt++;
                    window[s2[left] - 'a']--;
                }
                left++;
            }

            right++;
        }
        return 0;
    }
};