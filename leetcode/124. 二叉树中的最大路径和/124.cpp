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
    int ans = INT_MIN;

    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int me = node->val;
        ans = max({ans, left + right + me});
        return max(max(left, right) + me, 0);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};