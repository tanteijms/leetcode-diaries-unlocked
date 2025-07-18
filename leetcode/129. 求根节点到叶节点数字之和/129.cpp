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
    int sumNumbers(TreeNode *root, int x = 0) // 设定函数默认值，C++允许
    {
        if (!root)
            return 0;
        x = x * 10 + root->val;
        if (!(root->left || root->right))
            return x;
        return sumNumbers(root->left, x) + sumNumbers(root->right, x);
        // 该x是从上往下进行累加的结果，需要传入下面的
        // 在该函数的外部调用sumNumbers，不传入x是没问题的，是参数默认值
    }
};