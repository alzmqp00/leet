#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include<queue>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() % 2 != 0)
        {
            return false;
        }
        bool res = 0;
        stack<char> left;
        queue<char> right;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                left.push(s[i]);
            }
            else {
                right.push(s[i]);
            }
        }
        if (!left.empty())
        {
            return false;
        }
        else
            return true;
    }
};