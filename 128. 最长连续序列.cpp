#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> marked;
        int res = 0;
        // unordered_map<int, int> m;
        unordered_set<int> m;
        for (int num : nums)
        {
            m.insert(num);
        }
        for (int num : nums)
        {
            if (marked.count(num))
            {
                continue;
            }
            int left=0;
            int right =0;
            int i=1;
            while(m.count(num-i)){
                marked.insert(num-i);
                left++;
                i++;
            }
            i=1;
            while(m.count(num+i)){
                marked.insert(num+i);
                right++;
                i++;
            }
            res = max(res, left + right + 1);
            marked.insert(num);
        }
        return res;
    }
};