#include <bits/stdc++.h>
using namespace std;
// 這題因為我一開始沒有發現need的大小會變大 照理來說是過了第一個For後不會改變
// 但我忘記 在need.[s[right]] > 0的操作上 如果s[right]還不存在的話 map會建立一個<right,0>
// need.count(s[right]) > 0才是正確的
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return {};

        vector<int> res;
        unordered_map<char, int> need, window;
        for (int i = 0; i < p.size(); i++)
        {
            need[p[i]]++;
        }

        int vaild = 0;
        int left = 0;
        int right = 0;
        /*s =
    "cbaebabacd"
p =
    "abc"*/
        while (right < s.size())
        {
            if (need.count(s[right]) > 0)
            {
                window[s[right]]++;
                if (need[s[right]] == window[s[right]])
                    vaild++;
            }
            while (right - left + 1 > p.size())
            {
                if (need.count(s[left]) > 0)
                {
                    if (need[s[left]] == window[s[left]])
                        vaild--;
                }
                window[s[left]]--;
                cout << left << "" << vaild << endl;
                left++;
            }
            if (vaild == need.size())
                res.push_back(left);

            right++;
        }
        return res;
    }
};