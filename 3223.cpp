#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int minimumLength(string s)
    {
        int sum = 0;
        vector<int> v(26, 0);
        for (auto S : s)
        {
            v[S - 'a']++;
        }

        for (auto V : v)
        {
            if (V % 2 == 1)
                sum++;
            else if (V != 0)
                sum += 2;
        }
        return sum;
    }
};