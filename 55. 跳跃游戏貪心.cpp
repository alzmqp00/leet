#include <bits/stdc++.h>
using namespace std;
/*用貪心



*/
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int fur = nums[0];    // fur是 現在可到達的最遠位置 預設nums[0]
        if (nums.size() == 1) //{0}要回傳1
            return 1;
        // 從1開始 因為0已經int fur = nums[0];
        for (int i = 1; i <= fur; i++)
        {
            // 對於每一個位置 都試圖更新目前可到達的最遠
            fur = max(fur, i + nums[i]);
            if (fur >= nums.size() - 1) // 一但超過 就為1
                return 1;
        }
        return 0;
    }
};