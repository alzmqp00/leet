#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
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
        // stack<char> right;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                left.push(s[i]);
            }
            else
            {
                if (left.empty())
                {
                    return 0;
                }
                else if (s[i] == ')')
                {
                    if (left.top() == '(')
                    {
                        left.pop();
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (s[i] == ']')
                {
                    if (left.top() == '[')
                    {
                        left.pop();
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (s[i] == '}')
                {
                    if (left.top() == '{')
                    {
                        left.pop();
                    }
                    else
                    {
                        return 0;
                    }
                }
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