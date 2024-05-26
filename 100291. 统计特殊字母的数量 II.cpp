#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string s)
    {
        // char temp= 'a';//97
        // char temsp= 'A';//65
        int res = 0;
        map<char, int> s1; // char,index
        map<char, int> s2;
       // set<char> se;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 97)
            {
            s1[s[i]]=i;
            }
            else
               s2.insert({s[i],i});
        }
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        
        while (it1 != s1.end() && s2.end() != it2)
        {
            if ((it1->first) - 32 < it2->first)
                it1++;
            else if ((it1->first) - 32 > it2->first)
                it2++;
            else
            {   
                if ((it1->second)<it2->second)
                    res++;
                it1++;
                it2++;
            }
        }
        return res;
    }
};
/*给你一个字符串 word。如果 word 中同时存在某个字母的小写形式和大写形式，则称这个字母为 特殊字母 。

返回 word 中 特殊字母 的数量。



示例 1:

输入：word = "aaAbcBC"

输出：3

解释：

word 中的特殊字母是 'a'、'b' 和 'c'。*/