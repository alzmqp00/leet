#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        int res = 0;
        // unordered_map<int, int> m;
        unordered_set<int> m;
        for (int num : nums)
        {
            m.insert(num);
        }
        for (int num : nums)
        {
            if (!m.count(num - 1))
            {
                            int right = 0;
            int i = 1;

            while (m.count(num + i))
            {
                right++;
                i++;
            }
            res = max(res, right + 1);
            }
            // int left=0;

           
        }
        return res;
    }
};