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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        stk.push(root);
        while (!stk.empty())
        { /*在迴圈中，我們首先處理所有的左子節點。
      將其值添加到結果中，推入堆疊，
      並將當前節點設置為其左子節點。我們重複這個過程，
      直到我們達到一個沒有左子節點的節點。*/
            while (node != nullptr)
            {
                res.push_back(node->val);
                stk.push(node);
                node = node->left;
            }
            /*處理完所有的左子節點後，我們從堆疊中彈出一個節點
            ，並將當前節點設置為該節點的右子節點。
            這樣，我們就可以在下一次迴圈中處理這個右子節點和它的所有左子節點。*/

            // 到這裡的一定是沒有左子節點的節點
            node = stk.top();   // node=沒有左子節點的最後一個節點
            stk.pop();          // 沒有左子節點的節點不要了
            node = node->right; // 對於沒有左子節點的節點，進入右子節點 因為此時中、左子節點都已經處理完了
        }
        return res;
    }
};