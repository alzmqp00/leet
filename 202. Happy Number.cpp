/*Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
2 4 16 37 9+49=58 25+64=89 81+64=145 17+25=42 20
*/
#include <bits/stdc++.h>
using namespace std;
/*class Solution
{
public:
    bool isHappy(int n)
    {
        map<int, bool> m;
        int res;
        int sum = n, temp = n;
        while (sum != 1)
        {
            if (m[sum] == true)
            {
                return false;
            }
            else
                m[sum] = true;
            temp = sum;
            sum=0;
            while (temp != 0)
            {
                int r = temp % 10;
                temp /= 10;
                sum += r * r;
            }
            //2 4 16 37 9+49=58 25+64=89 81+64=145 17+25=42 20
        }
        return 1;
    }
};*/
class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> s;
        int res;
        int sum = n, temp = n;
        while (sum != 1)
        {
            if (s.count(sum)==1)
            {
                return false;
            }
            else
                s.insert(sum);
            temp = sum;
            sum=0;
            while (temp != 0)
            {
                int r = temp % 10;
                temp /= 10;
                sum += r * r;
            }
            //2 4 16 37 9+49=58 25+64=89 81+64=145 17+25=42 20
        }
        return 1;
    }
};