#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;
        string temp, temp1;
        while (left <= right)
        {
            if (s[left] != s[right])
            {   //aydmda 1 4 2 
                temp = s.substr(left + 1, right - left + 1);
                reverse(temp.begin(), temp.end());
                if (temp == s.substr(left + 1, right - left + 1))
                    return 1;
                temp1 = s.substr(left, right - left);
                reverse(temp1.begin(), temp1.end());
                if (temp1 == s.substr(left, right - left))
                    return 1;
                return 0;
            }
            left++;right--;
        }
        return 1;
    }
};