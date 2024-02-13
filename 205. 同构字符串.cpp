#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> mapping(26, -1);
        vector<bool> used(26, false);
        for (int i = 0; i < s.size(); i++)
        {
            if (mapping[s[i] - 'a'] == -1 && !used[t[i] - 'a'])
            {
                mapping[s[i] - 'a'] = t[i] - 'a';
                used[t[i] - 'a'] = true;
            }
            else if (mapping[s[i] - 'a'] != t[i] - 'a')
            { // 已經涵蓋了mapping[s[i] - 'a'] == -1 && used[t[i]-'a']的情況
                // 當這種情況發生時 mapping[s[i] - 'a'] != t[i] - 'a'->-1 != t[i] - 'a' 為true
                return false;
            }
        }
        return true;
    }
};