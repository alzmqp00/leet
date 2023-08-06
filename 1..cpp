#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> v1;
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                v1.push_back(nums.at(i));
            }
        }
        return v1;
    }
};
