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
    TreeNode *expandBinaryTree(TreeNode *root)
    {
        visit(root);
        return root;
    }
    void visit(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->left)
        {
            TreeNode *node = new TreeNode(-1, root->left, nullptr);
            visit(root->left);
            root->left = node;
        }
        if (root->right)
        {
            TreeNode *node = new TreeNode(-1, nullptr, root->right);
            visit(root->right);
            root->right = node;
        }
    }
};