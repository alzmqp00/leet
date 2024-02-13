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
// 這是ai寫的 我自己寫的在下面
/*我的程式無法正確的判斷需要交換的點，例如:321 程式發現3>2錯的
因此以為第一個要交換的點是2

*/
class Solution
{
public:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;

    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(first->val, second->val);
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        /*
        EX:0321
        這段邏輯是每兩兩比較，如果發現不是升序(32)先把這兩個當成要交換的點
        其中第一次發現的前面的數字一定是要交換的點
        最後一次發現的第二個數字一定是要交換的點
        */

        if (prev != nullptr && root->val < prev->val)
        {
            if (first == nullptr)
            {
                first = prev;
            }
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
};
/*
class Solution
{
public:
    TreeNode *wrong = nullptr;
    bool findwrong = false;
    bool finishSwap = false;
    void recoverTree(TreeNode *root)
    {
        // inorder
        int pre = INT_MIN;
        inorder(root, pre);
        pre = INT_MIN;
        swapNode(root, pre);
        return;
    }
    void inorder(TreeNode *root, int &pre)
    {
        if (root == nullptr || findwrong)
            return;
        inorder(root->left, pre);
        if (root->val < pre)
        {
            wrong = root;
            findwrong = true;
        }
        pre = root->val;
        inorder(root->right, pre);
    }
    // 1 3 5 6 7 2 10
    // 9 5 6 7 2 10
    void swapNode(TreeNode *root, int &pre)
    {
        if (root == nullptr || finishSwap)
            return;
        swapNode(root->left, pre);
        if (pre < wrong->val && wrong->val < root->val)
        {
            swap(root->val, wrong->val);
            finishSwap = true;
            return;
        }
        swapNode(root->right, pre);
    } // 321 我:231 要:123
};//0321*/