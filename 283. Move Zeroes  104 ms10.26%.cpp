#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    { // 001
        int i = 0;
        int size = nums.size();
        while (i < size)
        {
            if (nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                size--;
                nums.push_back(0);
            }
            else
                i++;
        }
    }
};