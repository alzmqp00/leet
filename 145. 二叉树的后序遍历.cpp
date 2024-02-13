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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        TreeNode *prev = nullptr;
        // stk.push(root); // 刪除這行
        // 主要思想：
        // 由于在某颗子树访问完成以后，接着就要回溯到其父节点去
        // 因此可以用prev来记录访问历史，在回溯到父节点时，可以由此来判断，
        // 上一个访问的节点是否为右子树
        while (!stk.empty() || node != nullptr)
        {
            while (node != nullptr)
            {
                //  res.push_back(node->val);
                stk.push(node);
                node = node->left;
            }
            /*从栈中弹出的元素，左子树一定是访问完了的。*/
            node = stk.top();
            stk.pop();
            // 现在需要确定的是是否有右子树，或者右子树是否访问过
            // 如果没有右子树，或者右子树访问完了，也就是上一个访问的节点是右子节点时
            // 说明可以访问当前节点
            if (prev == node->right || node->right == nullptr)
            {
                res.push_back(node->val);
                prev = node;
                node = nullptr; //?// 避免重复访问左子树[设空节点]
            }
            else
            {
                stk.push(node); // 重复压栈以记录当前路径分叉节点
                node = node->right;
            }
        }
        return res;
    }
};