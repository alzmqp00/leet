#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size(); // 3%7=2

        for (int i = 0; i < k; i++)
        { // 重複k次把最後面的元素轉到前面
            int j = nums.size() - 1;
            while (j > 0)
            {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }
    }
};