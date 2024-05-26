#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int res;
        string a = to_string(x);
        if (a[0] == '-')
        {
            std::reverse(a.begin() + 1, a.end());
        }
        else
        {
            std::reverse(a.begin(), a.end());
        }
        try
        {
            res = stoi(a);
            return res;
        }
        catch (const std::exception &e)
        {
            return 0;
        }
    }
};