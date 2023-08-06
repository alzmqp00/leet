#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        map<int, char> m;
        string res("");
        for (int i = 0; i < s.length(); i++)
        {
            m.insert(pair<int, char>(indices[i], s[i]));
        }
        for (int i = 0; i < s.length(); i++)
        {
            res += m[i];
        }
        return res;
    }
};