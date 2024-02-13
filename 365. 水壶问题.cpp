#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        int GCD = gcd(jug1Capacity, jug2Capacity);
        if (targetCapacity % GCD == 0 && targetCapacity <= jug1Capacity + jug2Capacity)
            return 1;
        else
            return 0;
        return 0;
    }
};