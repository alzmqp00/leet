#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // sort(nums.begin(), nums.end()); 印出的索引值和原本的nums不同
        multimap<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m.insert({nums[i], i});
        }
        auto sta = m.begin();
        auto end = --m.end();
        while (sta != end)
        {
            // 3 3 t:6
            if (sta->first + end->first == target)
            {
                return {sta->second, end->second};
            }
            /* else if (sta->first > target || end->first < target)
             {
                 return {};
             }*/
            else if (sta->first + end->first < target)
            {
                sta++;
            }
            else
            {
                end--;
            }
        }

        return {};
    }
};