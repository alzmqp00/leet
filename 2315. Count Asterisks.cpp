#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    int countAsterisks(string s)
    {
        int res = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '|')
            {
                count += 1;
            }
            if (count % 2 == 0)
            {
                if (s[i] == '*')
                {
                    res += 1;
                }
            }
        }
        return res;
    }
};