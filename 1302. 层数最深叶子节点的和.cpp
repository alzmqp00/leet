#include "bits/stdc++.h"
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
    int deep = 0;
    int deepestLeavesSum(TreeNode *root)
    {
        int cnt = 0;
        queue<TreeNode *> q;
        findDeepestLeaves(root, 1);
        if (deep == 1)
            return root->val;
        q.push(root);
        int times = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                if (times == deep)
                    cnt += q.front()->val;
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
            times++;
        }
        return cnt;
    }
    void findDeepestLeaves(TreeNode *root, int deeptemp)
    {
        if (root == nullptr)
            return;
        deep = max(deep, deeptemp);
        findDeepestLeaves(root->left, deeptemp + 1);
        findDeepestLeaves(root->right, deeptemp + 1);
    }
};
