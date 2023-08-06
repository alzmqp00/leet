#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int res = 0;
        char state = 1;
        int i = 0;
        while (n != 0)
        {
            i++;
            if (state == 1)
            {
                res += n % 10;
                n /= 10;
                state = -1;
            }
            else
            {
                res -= n % 10;
                n /= 10;
                state = 1;
            }
            cout << state << endl;
        }
        if (i % 2 == 0)
            res *= -1;
        return res;
    }
};