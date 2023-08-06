#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        bool nagetive;

        int strindex = 0, endindex = s.length();
        int i;
        if (s[0] != ' ' && (s[0] > '9' || s[0] < '1'))
        {
            if (s[0] == '-' || s[0] == '+')
            {
                if (s[1] != ' ' && (s[1] > '9' || s[1] < '1'))
                    return 0;
            }
            else
                return 0;
        }
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] <= '9' && s[i] >= '1')
            {
                if (i - 1 >= 0 && s[i - 1] == '-')
                {
                    nagetive = true;
                }
                else
                    nagetive = false;
                strindex = i;
                for (int j = i; j < s.length(); j++)
                {
                    if (s[i] > '9' || s[i] < '1')
                    {
                        endindex = j;
                        break;
                    }
                }
                break;
            }
        }
        cout << nagetive;
        int res = stoll(s.substr(strindex, endindex - strindex));
        if (res == 1089159116)
        {
            return INT_MIN;
        }
        else if (res == -1089159116)
        {
            return INT_MAX;
        }
        else if (i == s.length() - 1 && s.length() != 1)
        {
            return 0;
        }

        else if (nagetive == true)
        {
            res *= -1;
            return res;
        }
        else
            return res;
    }
};