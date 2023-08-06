#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/*vector<string> atostring(string q)
{
    int frontindex = 0;
    vector<string> res = {};
    for (int i = 0; i < q.length(); i++)
    {
        if (q[i] == ' ')
        { // 3 5=' '
            res.push_back(q.substr(frontindex, i - frontindex));
            frontindex = i + 1;
        }
    }
    res.push_back(q.substr(frontindex));

    return res;
}*/
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        string q = s1 + " " + s2;
        int frontindex = 0;
        int index = 0;
        vector<string> s = {};
        for (int k = 0; k < q.length(); k++)
        {
            if (q[k] == ' ')
            { // 3 5=' '
                s.push_back(q.substr(frontindex, k - frontindex));
                cout << q.substr(frontindex, k - frontindex) << "\t" << k - frontindex << "\t" << frontindex << endl;
                frontindex = k + 1;
            }
        }

        s.push_back(q.substr(frontindex));

        // vector<string> s = atostring(s3);

        sort(s.begin(), s.end());
        int i = 0;
        string temp("");
        // while (i < s.size()) 我沒有注意到s[i + 1]會超出範圍
        while (i < s.size() - 1)
        {
            if (s[i] == s[i + 1])
            {
                string temp = s[i];
                while (temp == s[i])
                {
                    s[i] = "0";
                    i++;
                    // s.erase(s.begin() + i);
                }
            }
            else
            {
                i++;
            }
        }
        vector<string> res1 = {};
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != "0")
            {
                res1.push_back(s[i]);
            }
        }
        return res1;
    }
};
int main()
{
    string s1 = "this apple is sweet", s2 = "this apple is sour";
    Solution a; // 30
    vector<string> s = a.uncommonFromSentences(s1, s2);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}