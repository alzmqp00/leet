/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // int minnum = INT32_MAX;
        // int minindex;
        for (int i = nums.size() - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            { // 因為要找「下一個數字」 所以要改變的數字要盡量在右側
                // 尋找第一個非降序的nums[i] ex 5642 54321
                // 從左側的降序窗口(降序代表 這一串數字的排列已經是最大 因此沒有辦法再變大) ex54321
                // 要改變的數字要盡量在右側 但降序 這一串數字的排列已經是最大 所以沒辦法再變大
                // 因此第一個發現不降序的數字 就是最右邊的可交換(改變)的數字
                // 從54321中找大於nums[i-1]的但最小的數字 (2) 交換 再排序 排序後的一定是最小
                //             ex3                          5643 54221-> 5643 12245

                for (int j = nums.size() - 1; j > i - 1; j--)
                {
                    if (nums[j] > nums[i - 1])
                    {
                        swap(nums[j], nums[i - 1]);
                        break;
                    }
                }
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end
