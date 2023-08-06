#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &h)
    {
        int max = 0;
        int v; // 容積
        int first = 0, end = h.size() - 1;
        while (first < end)
        {
            int minelement = min(h[first], h[end]);
            v = minelement * abs(first - end);
            cout << v << " "; // 發現這個就花了400ms
            if (v > max)
            {
                max = v;
            }
            if (h[first] < h[end])
            {
                first++;
            }
            else
            {
                end--;
            }
        }
        return max;
    }
};