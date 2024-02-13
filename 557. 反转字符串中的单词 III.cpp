#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        int left = 0, right = 0;
        string res = "";
        string temp;
        while (right < s.length() - 1)
        {
            if (s[right] == ' ')
            { //                 2     5
                temp = s.substr(left, right - left);
                reverse(temp.begin(), temp.end());
                res += temp + ' ';
                left = right + 1;
            }
            right++;
        }
        temp = s.substr(left, s.length() - left);
        reverse(temp.begin(), temp.end());
        res += temp;
        return res;
    }
};
/*int main()
{

   system("pause");
   return 0;
}*/
