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
//[1,null,2,3,4,null,5]過不了 這是錯誤的
class Solution
{
public:
    int maxdeep = 0; // 在dfs裡存深度
    int tardeep = 0; // 目標所在的深度
    int amountOfTime(TreeNode *root, int start)
    {
        if (root == nullptr)
            return 0;
        // if (root == nullptr || start == root->val)
        /*|| start == root->val要改掉 root->val==sta不代表0次操作就可感染完成
        雖然這樣會有一個問題 兩次bfs的起點是左右子節點 因此如果root就是sta的目標的話
        tardeep將不會更新 但是tardeep的預設值是0
        所以在return那邊 會等價max(rightsum, leftsum ) 正確
        所以不需要修改其他地方
        */
        int maxsum = 0;  // 左側、右側深度
        bool atleft = 0; // 有沒有在左子樹
        TreeNode *left = root->left;
        bfs(left, maxsum, start);
        if (tardeep != 0) // 還是預設值
            atleft = 1;
        int leftsum = maxdeep; // 左子樹的深度
        maxdeep = 0;
        TreeNode *right = root->right;
        bfs(right, maxsum, start);
        int rightsum = maxdeep;
        if (atleft)
            return max(rightsum + tardeep, leftsum - tardeep);
        else
            return max(leftsum + tardeep, rightsum - tardeep);
    }
    void bfs(TreeNode *root, int &maxsum, int &start)
    {
        if (root == nullptr)
            return;
        maxsum++;
        maxdeep = max(maxsum, maxdeep);
        if (root->val == start)
            tardeep = maxsum;
        bfs(root->left, maxsum, start);
        bfs(root->right, maxsum, start);
        maxsum--;
    }
};