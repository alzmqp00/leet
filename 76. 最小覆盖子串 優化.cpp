#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<char, int> hashmap;
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";
        int left = 0, leftTemp = 0, rightTemp = 0;
        int minlen = INT32_MAX;
        int need_cnt = t.size(); // 需要的字母數 這樣就不用一直迴圈check
        for (int i = 0; i < t.length(); i++)
        {
            hashmap[t[i]]++;
        }
        for (int right = 0; right < s.length(); right++)
        {
            // 遇到了需要的字母 就減去
            if (hashmap[s[right]] > 0)
            {
                need_cnt--;
            }
            // 沒在t中出現的字母會變成負數或是 有在t中出現但是s中出現好幾次的時候 也會變成負數
            // 其他有在t中出現的慢慢減少成0 反正就是記下需要的字母剩下那些
            hashmap[s[right]]--;

            // 全部都找到了 縮短左邊看看能不能優化
            if (need_cnt == 0)
            { // 代表有不需要或多餘的字母
                while (hashmap[s[left]] < 0)
                {
                    hashmap[s[left]]++;
                    left++;
                }
                // 這個if要在while外面 不然當s==t時(沒有多餘字母)minlen不會被更改而輸出"" 正確是輸出s 或 t(依樣)
                if (minlen > right - left + 1)
                {
                    leftTemp = left;
                    rightTemp = right;
                    minlen = right - left + 1;
                }
                // 原本的left會停在第一個用的到的字母上
                need_cnt++;
                hashmap[s[left]]++;
                left++; // 破壞條件 捨棄那個字母 繼續往右邊擴張
            }
        }
        // 如果 while (check()) 沒有執行過的話 那麼s.substr(leftTemp, minlen);的leftTemp是沒有經過驗證的預設值0
        if (minlen != INT32_MAX)
            return s.substr(leftTemp, minlen);
        else
            return "";
    }
};