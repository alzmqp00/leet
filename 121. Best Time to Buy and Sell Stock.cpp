#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;
        int ptr = 0;
        int res = 0, diff = 0;
        int curmin = INT_MAX;
        int curmax = INT_MIN;
        while (ptr != prices.size())
        {
            if (prices[ptr] < curmin)
            {   
                curmin = prices[ptr];
                curmax = INT_MIN;
            }
            else if (prices[ptr] > curmax)
            {
                curmax = prices[ptr];
                diff = curmax - curmin;
                if (diff > res)
                    res = diff;
            }

            ptr++;
        }
        return res * (res > 0);
    }
};