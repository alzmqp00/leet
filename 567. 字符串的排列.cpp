#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
            return 0;
        int need_cnt = s1.length();
        vector<int> hash(26, 0);
        vector<int> ori(26, 0);
        bool conti = 0;
        //"eidboaoo" "ab"
        for (int i = 0; i < s1.length(); i++)
        {   
            hash[s1[i] - 'a']++;
            ori[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++)
        {
            if (hash[s2[i] - 'a'] > 0)
            {
                if (conti = 0)
                {
                    need_cnt = s1.length();
                    hash = ori;
                }
                need_cnt--;
                hash[s2[i] - 'a']--;
                conti = 1;
                if (need_cnt == 0)
                {
                    return 1;
                }
            }
            else
            {
                conti = 0;
                need_cnt = s1.length();
                hash = ori;
            }
        }
        return 0;
    }
};