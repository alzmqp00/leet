/*class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(),nums.end());
        int res = 0;
        for (int num : nums) {
            res += num - minNum;
        }
        return res;
    }
};*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int res = 0;
        int min = *min_element(nums.begin(), nums.end());
        for (auto it : nums)
        {
            min = *min_element(nums.begin(), nums.end());
            res += it - min;
        }
        return res;
    }
};
