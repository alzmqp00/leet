#include <bits/stdc++.h>
using namespace std;
// ninninja ninnnnja
int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
        return 0;
    int lastChar;
    deque<char> Char;
    lastChar = 0;
    int left = 0, right = 1, len = 1;
    Char.push_back(s[0]);
    // afftaf
    while (left < right && right < s.length())
    {
        //   cout << left << " " << right << endl;
        if (Char.size() < 2)
        {
            if (Char.empty() || Char.back() != s[right])
            {
                Char.push_back(s[right]);
            }
        }
        else
        {
            if (s[right] != Char.back() && s[right] != Char.front())
            {
                if (s[right - 1] == Char.back())
                    Char.pop_front();
                else
                    Char.pop_back();
                Char.push_back(s[right]);
                left = lastChar;
            }
        }
        if (s[lastChar] != s[right])
        {
            lastChar = right;
        }
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}
int main()
{
    string a;
    while (in >> a)
        cout << lengthOfLongestSubstring(a) << endl;
}
