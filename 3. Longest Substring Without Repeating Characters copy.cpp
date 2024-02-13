#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> lookup;
        int count = 0, max = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            while (lookup.find(s[i]) != lookup.end())
            {
                lookup.erase(s[start]);
                start++;
            }
            lookup.insert(s[i]);
            count = i - start + 1;
            max = max > count ? max : count;
        }

        return max;
    }
};
int main()
{
    Solution a;
    cout << a.lengthOfLongestSubstring("dvdf");
}