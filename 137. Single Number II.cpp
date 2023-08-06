#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, bool> m;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = m.insert({nums[i], true});
            if (it.second == false)
            {
                m[nums[i]] = false;
            }
        }
        for (auto it1 = m.begin(); it1 != m.end(); it1++)
        {
            if (it1->second == true)
            {
                return it1->first;
            }
        }
        return -1;
    }
};