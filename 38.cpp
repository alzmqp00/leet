#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string temp = "";
        string x = countAndSay(n - 1);
        int count = 1;
        if (x.length() == 1)
        {
            temp.push_back('1');
            temp.push_back(x[0]);
        }

        for (int i = 0; i < x.length() - 1; i++)
        { // 3322251 3522255 3222551
            if (x[i] == x[i + 1])
            {
                count++;
                if (i + 1 == x.length() - 1)
                {
                    temp.push_back(count + '0');
                    temp.push_back(x[i]);
                    break;
                }
                continue;
            }

            temp.push_back(count + '0');
            temp.push_back(x[i]);
            if (i + 1 == x.length() - 1)
            {
                temp.push_back('1');
                temp.push_back(x[i + 1]);
                break;
            }

            count = 1;
        }
        return temp;
    }
};

// temp.push_back(count - '0'); 要改成 temp.push_back(count + '0');