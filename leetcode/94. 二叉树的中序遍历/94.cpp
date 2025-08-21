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
    vector<int> ans;

    void dfs(TreeNode *node)
    {
        // 如果空结点
        if (!node)
            return;
        dfs(node->left);
        ans.emplace_back(node->val);
        dfs(node->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};