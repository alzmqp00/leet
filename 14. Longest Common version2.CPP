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
        sort(strs.begin(), strs.end());
        string res("");
        int i = 0;
        // minstrs[0].length(),strs[strs.size() - 1])
        while (res.length() < strs[0].length() && res.length() < strs[strs.size() - 1].length())
        {
            if (strs[0][i] == strs[strs.size() - 1][i])
            {
                res += strs[0].substr(i, 1);
            }
            else
                break;
            i++;
        }
        return res;
    }
};