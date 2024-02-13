#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> hashmap;
    vector<int> hashmapTemp;
    bool check()
    {
        for (int i = 0; i < 123; i++)
        {
            if (hashmapTemp[i] < hashmap[i])
                return 0;
        }
        return 1;
    }
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";
        hashmap.assign(123, 0);
        hashmapTemp.assign(123, 0);

        int left = 0, leftTemp = 0, rightTemp = 0;
        int minlen = INT32_MAX;
        // int right = 0;

        for (int i = 0; i < t.length(); i++)
        {
            hashmap[t[i]]++;
            // hashmapTemp[t[i] - 'a']++;
        }
        //"ADOBECODEBANC" ABC
        for (int right = 0; right < s.length(); right++)
        {
            if (hashmap[s[right]])
            {
                hashmapTemp[s[right]]++;
            }
            while (check())
            {
                if (minlen > right - left + 1)
                {
                    leftTemp = left;
                    rightTemp = right;
                    minlen = right - left + 1;
                }
                if (hashmapTemp[s[left]] > 0)
                    hashmapTemp[s[left]]--;
                left++;
            }
        }
        // 如果 while (check()) 沒有執行過的話 那麼s.substr(leftTemp, minlen);的leftTemp是沒有經過驗證的預設值0
        if (minlen != INT32_MAX)
            return s.substr(leftTemp, minlen);
        else
            return "";
    }
};