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
    bool res = 0;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bfs(root, targetSum, 0);
        return res;
    }
    void bfs(TreeNode *root, int targetSum, int sum)
    {
        if (root == nullptr)
        {
            return;
        }
        sum += root->val;
        if (sum == targetSum && root->left == nullptr && root->right == nullptr)
        {
            res = 1;
            return;
        }
        bfs(root->left, targetSum, sum);
        bfs(root->right, targetSum, sum);
    }
};