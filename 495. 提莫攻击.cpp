#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int res = 0;
        int lasttime = 0;
        for (int i = 0; i < timeSeries.size(); i++)
        {
            lasttime = timeSeries[i] + duration;
            if (i + 1 < timeSeries.size() && lasttime > timeSeries[i + 1])
            {
                res += timeSeries[i + 1] - timeSeries[i];
            }
            else
            {
                res += duration;
            }
        }
        return res;
    }
};