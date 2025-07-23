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
    TreeNode *invertTree(TreeNode *root)
    {
        // 如果是空节点，return nullptr
        if (!root)
            return nullptr;

        // 如果是叶子节点，不用交换
        if (!(root->left || root->right))
            return root;

        // 先递归左右子树，再交换他们
        TreeNode *temp = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = temp;

        return root;
    }
};