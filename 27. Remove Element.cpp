#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        int n = nums.size();
        int left = 0, right = 0;
        while (right != n)
        { //[0,1,2,2,3,0,4,2]
            if (nums[right] != val)
            {
                swap(nums[right], nums[left++]);
                count++;
            }
            right++;
        }
        return count;
    }
};