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
    TreeNode *dfs(TreeNode *node)
    {
        if (!node)
            return nullptr;
        TreeNode *left = dfs(node->left);
        TreeNode *right = dfs(node->right);
        // 两子树都处理完了，下面开始拼接
        // 注意这个left有可能是nullptr，所以要判断一步
        if (left)
        {
            left->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        TreeNode *result = (right ? right : (left ? left : node));
        return result;
    }

public:
    void flatten(TreeNode *root)
    {
        dfs(root);
    }
};