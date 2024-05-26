#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {   string res;
        map<int, string> m;
        m.insert({1, "I"});
        m.insert({4, "IV"});
        m.insert({5, "V"});
        m.insert({9, "IX"});
        m.insert({10, "X"});
        m.insert({40, "XL"});
        m.insert({50, "L"});
        m.insert({90, "XC"});
        m.insert({100, "C"});
        m.insert({400, "CD"});
        m.insert({500, "D"});
        m.insert({900, "CM"});
        m.insert({1000, "M"});
        auto it=m.rbegin();
        while(num!=0){
            while(num>=it->first){
                num-=it->first;
                res+=it->second;
            }
            it++;
        }
        return res;
    }
};