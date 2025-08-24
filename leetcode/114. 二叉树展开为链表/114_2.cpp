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
    TreeNode *head = nullptr;

public:
    void flatten(TreeNode *root)
    {
        // 原地构造，不要有额外的空间开辟
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};