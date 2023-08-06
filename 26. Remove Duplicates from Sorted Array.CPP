#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // 0,0,1,1,1,2,2,3,3,4
        // 1 1
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                int temp = nums[i];
                while (i + 1 < nums.size() && nums[i + 1] == temp)
                {
                    nums.erase(nums.begin() + i + 1);
                }
            }
        }
        return nums.size();
    }
};

/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};*/