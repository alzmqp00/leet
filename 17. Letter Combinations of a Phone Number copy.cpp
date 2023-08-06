#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    string temp = "";
    vector<string> res;
    map<int, string> m;

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        dfs(digits, 0);
        return res;
    }
    void dfs(string digits, int index)
    {
        if (index == digits.size())
        {
            res.push_back(temp);
            return;
        }
        else
        {
            int digit = digits[index] - '0';
            string letters = m[digit];
            for (int i = 0; i < letters.size(); i++)
            {
                temp.push_back(letters[i]); // 处理
                dfs(digits, index + 1);     // 递归，注意index+1，一下层要处理下一个数字了
                temp.pop_back();            // 回溯
            }
        }
    }
};
int main()
{
    Solution a;
    string dig("23");
    vector<string> s = a.letterCombinations(dig);

    for (auto x : s)
    {
        cout << x << " ";
    }
}