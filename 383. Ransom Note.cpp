#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int i = 0;
        int i2 = 0;
        if (ransomNote.length() > magazine.length())
            return 0;
        char last = '0';
        while (i != ransomNote.length())
        {

            if (i2 >= magazine.length())
                return 0;
            // bc aaaaaaaaaaacc
            if (ransomNote[i] == magazine[i2])
            {
                last = ransomNote[i];
                i++;
                i2++;
            }
            /* else if (magazine[i2] == last || last == '0')
             {
                 i2++;
             }*/
            else if (magazine[i2] <= ransomNote[i])
            {
                i2++;
            }
            else
                return 0;
        }
        return 1;
    }
};