#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        int back = nums.back();
        int i = nums.size() - 1;
        int target;
        int repeatindex;
        int element = 1;
        // 13577 1357 135577
        while (i > 0)
        {

            if (i == 0)
                return count;

            target = nums[i - 1];
            repeatindex = i;
            // 這個也是錯的 就是他害我一職界外
            while (nums.at(repeatindex - 1) == nums.back())
            {

                repeatindex--;
            }
            element = nums.size() - repeatindex; // 數量
            target = nums.at(repeatindex - 1);
            count += element * (nums.back() - target); // 大錯特錯
            cout << element * (nums.back() - target) << endl;
            cout << element << " " << nums.back() << " " << target << endl;
            // 2+
            i = repeatindex - 1;
        }
        return count;
    }
};
int main()
{
    Solution a;
    vector<int> n = {1, 3, 5, 7};
    cout << a.minMoves(n);
}