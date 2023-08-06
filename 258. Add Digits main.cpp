#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int addDigits(int num)
    {

        if (num < 10)
        {
            return num;
        }
         int sum;//不能在這裡初始化
        while (num >= 10)
        {
            sum = 0; // 這裡才對
            while (num != 0)
            {

                int r = num % 10;
                num = num / 10;
                sum += r;
            }
            num = sum;
        }
        return sum;
    }
};

int main()
{
    Solution a;
    cout << a.addDigits(38);
    return 0;
}