#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool compare(vector<int> a, vector<int> b)
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), compare);
    }
};