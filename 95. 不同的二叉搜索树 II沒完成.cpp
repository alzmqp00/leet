#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *pre;
    vector<TreeNode *> res;
    vector<TreeNode *> generateTrees(int n)
    {
    }
    void backtrack(int nodes, int &n, TreeNode *&root)
    {
        for (int i = 0; i < n; i++)
        {
            if (i)
        }
    }
};