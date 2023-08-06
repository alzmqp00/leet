#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count;
        int back = nums.back();
        int i = nums.size();
        int target;
        i--;
        // 13577
        while (i)
        {
            back = nums.back();
            target = nums[i - 1];
            if (nums[i - 1] == back)
            {
                while (nums[i - 1] == back)
                {
                    i--;
                }
                target = nums[i - 1];
            }
            else
            {
                for ()
            }
        }
        return 0;
    }
};