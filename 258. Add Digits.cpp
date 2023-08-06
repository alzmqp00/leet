#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int addDigits(int num)
    {

        if (num < 10)
        {
            return num;
        }
        int sum = 0;
        while (num >= 10)
        {
            while (num != 0)
            {

                int r = num % 10;
                num = num / 10;
                sum += r;
            }
            num = sum;
        }
        return sum;
    }
};
