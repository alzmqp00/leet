#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> res;
    string temp;
    int sum = 0;
    vector<string> restoreIpAddresses(string s)
    {
        if (s.length() <= 3)
            return {};
        temp = s;
        dfs(s, 1, 0);
        return res;
    }
    void dfs(string s, int index, int sum, int lastpoint = 0)
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

    bool check(string temp, int amont, int lastpoint, int index)
    {

        if (amont == 1)
        {
            cout << stoi(temp.substr(0, index)) << " 1 ";
            if (temp.substr(0, index).length() > 3 || stoi(temp.substr(0, index)) > 255)
            {
                return 0;
            }
            else
                return 1;
        }

        else if (amont == 3)
        { // 0.0.0.0
            cout << stoi(temp.substr(index + 1)) << " 3 " << endl;
            cout << (temp.substr(lastpoint + 1, index)) << " 3-2 " << endl;
            bool back = temp.substr(index + 1).length() > 3 || stoi(temp.substr(index + 1)) > 255;
            bool frint = temp.substr(lastpoint + 1, index).length() > 3 || stoi(temp.substr(lastpoint + 1, index)) > 255;
            if (back || frint)
            {
                return 0;
            }
            else
                return 1;
        }
        else if (amont == 2)
        {
            cout << stoi(temp.substr(lastpoint + 1, index)) << " 2 " << temp << endl;
            bool frint = temp.substr(lastpoint + 1, index).length() > 3 || stoi(temp.substr(lastpoint + 1, index)) > 255;
            if (frint)
            {
                return 0;
            }
            else
                return 1;
        }
        else if (amont == 0)
            return 1;
        return -1;
    }
    bool check2(string temp)
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
    vector<string> s = a.restoreIpAddresses("101023");
    for (auto x : s)
    {
        cout << x << endl;
    }
}
/*
for (int i = index; i < s.length(); i++)
            {
                cout<<i<<" ";
                temp.insert(i, ".");
                dfs(s, i + 0, sum + 1);
                temp.erase(i);
            }
            terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::replace: __pos (which is 1) > this->size() (which is 0)
for (int i = index; i < s.length(); i++)->for (int i = index; i < temp.length(); i++)


            */

/*原本的程式無法列出全部的可能 只能列出第一種 ex:
"25525511135"->2.5.5.25511135 問chat就修好了
發現是temp.erase(i);要改成temp.erase(i, 1); string的erase和vector的erase不一樣*/

/*
for (int i = index; i < s.length(); i++)
            {
                cout<<i<<" ";
                temp.insert(i, ".");
                dfs(s, i + 0, sum + 1);
                temp.erase(i);
            }
            terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::replace: __pos (which is 1) > this->size() (which is 0)
for (int i = index; i < s.length(); i++)->for (int i = index; i < temp.length(); i++)


            */

/*原本的程式無法列出全部的可能 只能列出第一種 ex:
"25525511135"->2.5.5.25511135 問chat就修好了
發現是temp.erase(i);要改成temp.erase(i, 1); string的erase和vector的erase不一樣*/
/*temp.substr(lastpoint + 1, i)這裡 我沒有發現問題 害我卡好久 它代表的是i個數字 要改成temp.substr(lastpoint + 1, i - lastpoint - 1)*/
// 不能有前綴0