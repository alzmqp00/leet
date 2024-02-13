#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int left = 0, right = 0;
        int oneSum = 0;     // 這次1的總和
        int lastoneSum = 0; // 上次
        int tempnum;        // 暫存nums[i]
        while (right < nums.size())
        {
            oneSum = 0; // 每次開始前要reset
            tempnum = nums[right];
            // 計算nums[i]的1的sum
            while (tempnum != 0)
            {
                oneSum += tempnum % 2;
                tempnum = tempnum / 2;
            }
            // 如果這次的1的和與上一次一樣 就不做事
            // right == 0 代表沒有上一次 直接過
            if (right == 0 || oneSum == lastoneSum)
            {
                right++;
            }
            else if (right != 0) // 好像多餘
            {
                sort(nums.begin() + left, nums.begin() + right); // 分段排列

                left = right;
                right++;

                /* for (auto x : nums)
                     cout << x << " ";
                 cout << endl;*/
            }
            lastoneSum = oneSum;
        }
        // 最後面的還沒有被分類過
        sort(nums.begin() + left, nums.begin() + right);
        return check(nums);
    }
    bool check(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
                return 0;
        }
        return 1;
    }
};
