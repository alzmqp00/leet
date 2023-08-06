#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool chance = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i] && chance == 1)
            { // 後面變大
                if ((i + 1 < nums.size() && nums[i + 1] < nums[i - 1]) && (i - 2 >= 0 && nums[i - 2] > nums[i]))
                    return 0;
                else if (i + 1 == nums.size())
                    return 1;
                chance = 0;
            }
            else if (chance == 0 && nums[i - 1] > nums[i])
            {
                return 0;
            }
        }
        return 1;
    }
};