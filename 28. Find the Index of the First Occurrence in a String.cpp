#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.length() > haystack.length())
            return -1;

        for (int i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[0])
            {
                if (i + needle.length() <= haystack.length() && needle == haystack.substr(i, needle.length()))
                {
                    return i;
                }
            }
        }
        return -1;
    }
};