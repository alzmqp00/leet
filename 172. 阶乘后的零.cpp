#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trailingZeroes(int n)
    {    int res = 0;
    /*
        int num = 5;
        if (n == 0)
            return 0;
        while (num <= n)
        {
            int temp = num;
            while (temp % 5 == 0)
            {
                res++;
                temp /= 5;
            }
            num += 5;
        }*/
        //5 10 15 20 25 
        while (n) {
            n /= 5;
            res += n;
        }
        return res;
    }
};