#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
            return 0;
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        while (magazine.length() != 0)
        {
            /*if (ransomNote.length() == 0)
                return 1; 這個放在這裡的話 如果兩者長度一樣
                ex:ransomNote ="aba"
                    magazine ="aab"  ->aab aab
                當達成條件(ransomNote.length() == 0)後，*/
            if (magazine.back() > ransomNote.back())
            {
                magazine.pop_back();
            }
            else if (magazine.back() == ransomNote.back())
            { // 在這裡達成條件ransomNote.length() == 0後，如果如上，則依然會跳出迴圈
                magazine.pop_back();
                ransomNote.pop_back();
                // 移到這裡才是對的
                if (ransomNote.length() == 0)
                    return 1;
            }
            else
                return 0;
        }
        return 0;
    }
};