#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (auto X : nums)
            cout << X << " ";
        if (nums.size() == 1 || nums[0] != nums[1])
            return nums[0];
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1])
            {
                return nums[i];
            }
            //  else i+=2;
        }
        return -1;
    }
};
/*int main()
{

   system("pause");
   return 0;
}*/
