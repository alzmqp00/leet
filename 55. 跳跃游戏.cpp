#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int right = 0; // 用來表示現在最遠已經到哪裡了 在這點之前的都一定是可到達的
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i + nums[i] >= nums.size() - 1)
            {
                return 1;
            }
            // 不斷更新現在最遠到哪
            right = max(right, i + nums[i]);
            // 如果i已經抵達了現在最遠的位置 那麼如果現在最遠的位置(i)本//身是0 那麼就不可能往後
            if (nums[right] == 0 && nums[i] == 0 && i == right)
            {
                return 0;
            }
        }
        // 當數組size=1時 return 1
        return 1;
    }
};