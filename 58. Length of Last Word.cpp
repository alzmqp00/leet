#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int left = 0;
        bool find = 0;
        int right = s.length() - 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != ' ' && find == 0)
            {
                find = 1;
                right = i;
            }

            if (s[i] == ' ' && find == 1)
            {
                return right - i;
            }
        }
        return right + 1;
    }
};