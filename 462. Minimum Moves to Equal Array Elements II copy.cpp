#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int res = 0;
        sort(nums.begin(), nums.end());
        int targetindex;
        // 0123 4 01234 5
        //  00168 3 midindex=3
        //169 15
        for (auto it : nums)
        {
            res += abs(it - nums[nums.size() / 2]);
        }
        return res;
    }
};