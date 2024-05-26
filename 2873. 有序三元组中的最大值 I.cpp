#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    res = max(res, static_cast<long long>(nums[i] - nums[j]) * static_cast<long long>(nums[k]));
                }
            }
        }
        return res;
    }
};