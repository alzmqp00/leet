class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums[0]>0||nums.size()<3)
        {
            return ans;
        }
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i]>0)
            {
                break;
            }
            if (i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            int L = i + 1; int R = nums.size() - 1;
            while (L < R)
            {
                int sums = nums[i] + nums[L] + nums[R];
                if (sums==0) 
                {
                    ans.push_back({ nums[i] ,nums[L] ,nums[R] });
                    while (L < R && nums[L] == nums[L + 1]) 
                    {
                        L++;
                    }
                    while (L < R && nums[R] == nums[R - 1])
                    {
                        R--;
                    }
                    L++; R--;
                }
                else if (sums<0) 
                {
                    L++;
                }
                else { R--; }
            }
        }
        return ans;

    }
};