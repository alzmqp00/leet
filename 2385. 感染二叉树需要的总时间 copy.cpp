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

int ans = 0;
int target;
int dfs(TreeNode *root)
{
    if (!root)
        return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    if (root->val == target)
    { // 当前节点是感染节点，将ans设置为子树深度
        ans = max(l, r);
        return -1;
    }
    if (l >= 0 && r >= 0)
        return max(l, r) + 1;   // 当前节点为根的子树中没有感染节点，返回子树深度
    ans = max(ans, abs(l - r)); // 当前节点为根的子树中有感染节点，用无感染节点子树返回的子树深度 + 有感染节点子树返回的感染点到当前节点的距离 更新答案
    return min(l, r) - 1;       // 返回感染节点距离当前节点的父亲节点的距离
}
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        target = start;
        dfs(root);
        return ans;
    }
};