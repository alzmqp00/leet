#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getLucky(string s, int k)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            s[i] -= 96;
            cout << int(s[i]) << " ";
        }
        for (int i = 0; i < s.length(); i++)
        {
            while (s[i] >= 10)
            {
                int r = s[i] % 10;
                sum += r;
                s[i] /= 10;
            }
            sum += s[i];
        }
        if (k == 1)
        {
            return sum;
        }
        int res = sum;
        cout << "sum: " << sum << endl;
        /* //if sum==50 next step is 5-> 5->5.... but at line 38
         for (int i = 0; i < k - 1; i++)
         {
             while (sum>= 10)
             {
                 int r = sum % 10;
                 res += r;
                 sum/= 10;
             }
             cout<<"sum: "<<sum<<endl;
             res+=sum;//if k==5,res=5+5+5+5 error
         }*/
        int i = 2; // int i=1會多算一次
        // 74 11 2
        while (i <= k && sum >= 10)
        {
            res = 0;
            while (sum >= 10)
            {
                int r = sum % 10;
                res += r;
                sum /= 10;
            }
            cout << "sum: " << sum << endl;
            res += sum;
            sum = res;
            i++;
        }
        return res;
    }
};