#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int min = 0;
        string res("");
        int index;
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[min].length() > strs[i].length())
            {
                min = i;
            }
        }
        bool state = 1;
        for (int i = 0; i < strs[min].length(); i++)
        {

            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[min][i])
                {
                    state = 0;
                    break;
                }
            }
            if (state == 0)
            {
                index = i; // 不是i-1 剛好會校正
                break;
            }
        }
        if (state == 1)
        {
            return strs[min];
        }
        if (index == 0)
        {
            return "";
        }
        else
        {
            res = strs[min].substr(0, index);
            return res;
        }
    }
};