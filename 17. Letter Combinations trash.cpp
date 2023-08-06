#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        string temp = "";
        vector<string> res;
        int cur = digits.length() - 1;
        int bot = digits.length() - 1;
        map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        if (digits.length() == 0)
            return {};
        else if (digits.length() == 1)
        {
            for (auto x : m[digits[0 - '0']])
            {
                temp.push_back(x);
                res.push_back(temp);
                temp = "";
            }
            return res;
        }
        vector<int> pointer(digits.length());
        /*Input: digits = "23" 236 3*3*3
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]*/
        while (!(bot == 0 && pointer[0] == m[digits[0] - '0'].length()))
        {
            for (int i = 0; i < digits.length(); i++)
            {

                temp += m[digits[i] - '0'][pointer[i]];
            }
            if (pointer[bot] != m[digits[bot] - '0'].length() - 1)
                pointer[bot]++;
            else
            {
                pointer[bot] = 0;
                if (bot == 0)
                    return res;
                pointer[--bot]++;
            }

            res.push_back(temp);
            temp = "";
        }

        return res;
    }
};
;