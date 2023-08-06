#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        if (s.length() == 1)
            return 1;
        int res = 0;
        bool findodd = 0;
        map<char, int> m;
        /*Input: s = "abccccdd"
Output: 7             dccaccd*/

        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        for (auto it : m)
        {
            if (it.second % 2 == 0)
                res += it.second;
            else
            {
                res += it.second - 1;
                findodd=1;
            }
        }
        if(findodd) res++;
        return res;
    }
};
