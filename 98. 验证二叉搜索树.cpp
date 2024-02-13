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
    bool res = 1;
    bool isValidBST(TreeNode *root)
    {
        vitit(root, INT64_MAX, INT64_MIN);
        return res;
    }
    void vitit(TreeNode *root, long Maxval, long Minval)
    {
        if (root == nullptr || res == 0)
            return;
        if (root->left)
        {
            if (root->left->val >= root->val || root->left->val >= Maxval || root->left->val <= Minval)
            {
                res = 0;
                return;
            }
            vitit(root->left, root->val, Minval);
        }

        if (root->right)
        {
            if (root->right->val <= root->val || root->right->val >= Maxval || root->right->val <= Minval)
            {
                res = 0;
                return;
            }
            vitit(root->right, Maxval, root->val);
        }
    }
};
/*Line 37: Char 62: runtime error: member access within null pointer of type 'TreeNode' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:46:62*/