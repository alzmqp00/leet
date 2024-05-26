#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
using namespace std;
/**
 * Calculates the greatest common divisor (GCD) of two numbers.
 *
 * @param a The first number.
 * @param b The second number.
 * @return The GCD of the two numbers.
 */
void gcd()
{
    int a, b;
    in >> a >> b;
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    cout << a;
}
int main()
{
    return 0;
}