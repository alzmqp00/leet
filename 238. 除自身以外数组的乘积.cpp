#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> pre(nums.size());
        vector<int> sub(nums.size());
        pre[0] = nums[0];
        sub[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = 1; i < nums.size(); i++)
        { // 從0~i的乘積(前綴)(不包含)
            pre[i] = nums[i] * pre[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // 從nums.size()-1~i的乘積 (後綴)(不包含)
            sub[i] = nums[i] * sub[i + 1];
        }
        vector<int> res(nums.size());
        // 前綴*後綴
        for (int i = 0; i < nums.size(); i++)
        {
            res[i] = 1;
            if (i > 0)
                res[i] *= pre[i - 1];
            if (i < nums.size() - 1)
                res[i] *= sub[i + 1];
        }
        return res;
    }
};