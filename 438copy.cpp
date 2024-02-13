#include <bits/stdc++.h>
using namespace std;
// 優化

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return {};

        vector<int> res;
        vector<int> need(26, 0);
        for (int i = 0; i < p.size(); i++)
        {
            need[p[i] - 'a']++;
        }

        int vaild = 0; // 注意不是map的話不好用 "有幾個不同的數字"當作驗證
        int left = 0;
        int right = 0;
        /*s =
    "cbaebabacd"
p =
    "abc"*/
        while (right < s.size())
        {

            if (need[s[right] - 'a'] > 0)
                vaild++;
            need[s[right] - 'a']--;
            cout << left << " " << right << " " << vaild << endl;
            if (vaild == p.size())
            {
                while (need[s[left] - 'a'] < 0)
                {
                    need[s[left] - 'a']++;
                    // cout << left << "" << vaild << endl;
                    left++;
                }

                //=0
                if (right - left + 1 == p.size())
                    res.push_back(left);

                // left++; 我一開始把 left++放這裡沒發現 它會改變下面那一行的left
                //  left++;應該要放在最後
                need[s[left] - 'a']++;
                vaild--;
                left++;
            }

            right++;
        }
        return res;
    }
};