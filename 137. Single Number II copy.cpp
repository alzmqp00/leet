#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &n)
    {
        sort(n.begin(), n.end());
        for (int i = 0; i < n.size(); i++)
        {
            cout << n[i] << " ";
        }
        // 1112223334555
        //99
        //[0 0 0 99 ] 7
        //[0,0,0,1,1,1,99,2,2,2....]
        for (int i = 0; i < n.size(); i++)
        {
            if (n.size() == 1 || n[0] != n[1])
                return n[0];
            else if (i + 4 < n.size() && n[i + 2] != n[i + 3] && n[i + 4] != n[i + 3])
            {
                return n[i + 3];
            }
            else if (i == n.size() - 1 || n.size()==4)
            {
                return n.back();
            }
            else
            {
                i += 2;
            }
        }
        return -1;
    }
};