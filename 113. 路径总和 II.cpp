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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        bfs(root, targetSum, 0, {});
        return res;
    }
    void bfs(TreeNode *root, int targetSum, int sum, vector<int> temp)
    {
        if (root == nullptr)
        {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if (sum == targetSum && root->left == nullptr && root->right == nullptr)
        {
            res.push_back(temp);
            return;
        }
        bfs(root->left, targetSum, sum, temp);
        bfs(root->right, targetSum, sum, temp);
        temp.pop_back();
    }
};