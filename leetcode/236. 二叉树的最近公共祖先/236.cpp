/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 若为空，或就是p或者q，直接终止递归，返回即可
        if (!root || root == p || root == q)
            return root;
        // 下面递归
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        if (left && !right)
            return left;
        return right; // 这个情况，left一定没有，也就是空，而right的话
        // 如果right有，那就是right，返回它
        // 如果right为空，那就不存在，返回nullptr
    }
};