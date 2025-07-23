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
    int getHeight(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = getHeight(node->left);
        if (left == -1)
            return -1;
        int right = getHeight(node->right);
        if (right == -1 || abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) != -1;
    }
};