#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> res;
    string temp;
    int sum = 0;
    vector<vector<string>> partition(string s)
    {
        if (s.length() <= 3)
            return {};
        temp = s;
        dfs(s, 1, 0);
        return res;
    }
    void dfs(string s, int index, int len, int lastpoint = 0)
    {

        if (sum == 3)
        {
            // cout << "sum : " << sum;
            // cout << temp;
            if (check2(temp))
            {
                res.push_back(temp);
            }

            return;
        }
        else
        {
            for (int i = index; i < temp.length(); i++)
            {
                // 0.0.0000.00       0 1     1 3
                temp.insert(i, ".");

                dfs(s, i + 2, sum + 1, i);

                temp.erase(i, 1);
            }
        }
    }

    bool check(string temp)
    {
        // cout << " a" << endl;
        int amo = 0; //.數量
        int lastpoint = -1;
        // 192.18.1.0
        for (int i = 0; amo != 3; i++)
        {

            if (temp[i] == '.')
            {
                amo++;

                if (amo != 3)
                {
                    if (temp.substr(lastpoint + 1, i - lastpoint - 1).length() > 3 || stoi(temp.substr(lastpoint + 1, i - lastpoint - 1)) > 255)
                        return 0;
                    if (temp.substr(lastpoint + 1, i - lastpoint - 1)[0] == '0' && temp.substr(lastpoint + 1, i - lastpoint - 1).length() != 1)
                        return 0;
                }
                else
                {
                    // cout << temp << endl;
                    if (temp.substr(lastpoint + 1, i - lastpoint - 1).length() > 3 || stoi(temp.substr(lastpoint + 1, i)) > 255)
                        return 0;
                    if (temp.substr(i + 1).length() > 3 || stoi(temp.substr(i + 1)) > 255)
                        return 0;
                    if (temp.substr(i + 1)[0] == '0' && temp.substr(i + 1).length() != 1)
                        return 0;
                    if (temp.substr(lastpoint + 1, i - lastpoint - 1)[0] == '0' && temp.substr(lastpoint + 1, i - lastpoint - 1).length() != 1)
                        return 0;
                }
                lastpoint = i;
            }
        }
        return 1;
    }
};
int main()
{
    Solution a;
    string dig("23");
    vector<vector<string>> s = a.restoreIpAddresses("101023");
    for (auto x : s)
    {
        cout << x << endl;
    }
}
