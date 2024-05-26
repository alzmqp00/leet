#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
   // char temp= 'a';//97
    // char temsp= 'A';//65
     int res=0;
     set<char> s1;
     set<char> s2;
     for(auto x:word){
        if(x>=97){
            s1.insert(x);
        }
        else
            s2.insert(x);
     }
     auto it1=s1.begin();
     auto it2=s2.begin();
    while(it1!=s1.end() && s2.end()!= it2){
        if(*it1-32>*it2)
            it2++;
        else if(*it1-32<*it2)
            it1++;
        else   {
            it1++;it2++;
            res++;
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