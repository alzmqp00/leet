#include <bits/stdc++.h>
using namespace std;
// is giving a run time error
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int Count = 0;
        // int num = n;
        vector<int> a = {2, 3, 5};
        for (int index = 1; index < INT_MAX; index++)
        {
            int num = index;
            while (num != 1)
            {
                for (int v : a)
                {
                    while (num % v == 0)
                    {
                        num /= v;
                    }
                }
                if (num != 1)
                {
                    Count--;
                    break;
                }
                else
                    Count++;
            }

            if (Count == n)
            {
                return index;
            }
        }
        return -1;
    }
};