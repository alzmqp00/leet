#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int i = 0;
        int res = 0;
        // 123
        while (x != 0)
        {
            if (i > 9)
                return 0;
            else if (x > 0 && (INT32_MAX - x % 10) / 10 < res)
                return 0;
            else if (x < 0 && (INT32_MIN - x % 10) / 10 > res)
                return 0;
            res = res * 10 + x % 10;
            x /= 10;
            i++;
        }
        return res;
    }
};