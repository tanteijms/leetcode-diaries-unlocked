/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        // 分类讨论
        // 1. 空
        if (!root)
            return 0;
        // 2. 叶子
        if (!(root->left || root->right))
            return 1;
        // 3. 有左或右子树，如果没有，就记为∞，防止误判
        int left = root->left ? minDepth(root->left) : INT_MAX;
        int right = root->right ? minDepth(root->right) : INT_MAX;

        return min(left, right) + 1;
    };
};