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
    vector<TreeNode *> nodes;

    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        nodes.emplace_back(node);
        dfs(node->left);
        dfs(node->right);
    }

public:
    void flatten(TreeNode *root)
    {
        // 先写数组存储结点实现
        dfs(root);
        if (nodes.empty())
            return;
        root = nodes[0];
        TreeNode *cur = root;
        for (int i = 1; i < nodes.size(); i++)
        {
            cur->right = nodes[i];
            cur->left = nullptr;
            cur = nodes[i];
        }
    }
};