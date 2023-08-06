#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int i = 1;
        int res = 0;
        //123
        if (x == 0 || abs(x) < 10)
        {
            return x;
        }

        while (x != 0)
        {
            res += (x % 10) * i++;
            x /= 10;
        }
        return res;
    }
};