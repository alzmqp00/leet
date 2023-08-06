#include <map>
#include <iostream>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            res += m[s[i]];
            if (m[s[i]] < m[s[i + 1]] && i != s.length() - 1)
            {
                res -= 2 * m[s[i]];
            }
        }
        return res;
    }
};