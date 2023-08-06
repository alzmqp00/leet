#include <bits/stdc++.h>
using namespace std;
/*1009 ms
Beats
5.67%

Memory
247.6 MB
Beats
5.58%
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> map;
        int count = 0, max = 0;
        int i = 0;
        while (i < s.length())
        {
            auto it = map.insert({s[i], i});
            if (it.second == false)
            {
                cout << count;
                if (count > max)
                {

                    max = count;
                }
                count = 0;
                i = map[s[i]] + 1;
                map.clear();
            }
            else
            {
                i++;
                count++;
            }
            if (count > max)
            {

                max = count;
            }
        }
        return max;
    }
};
int main()
{
    Solution a;
    cout << a.lengthOfLongestSubstring("dvdf");
}