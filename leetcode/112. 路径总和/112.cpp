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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 1. 若为空
        if (!root)
            return false;
        // 2. 当前递归到的节点非空，处理与targetSum的关系
        targetSum -= root->val;
        // 3. 判断是否为叶子，如果是叶子，且恰好加和为0，直接返回true
        if (!(root->left || root->right) && targetSum == 0)
            return true; // 如果是叶子节点，但不满足条件，会进入下面的return
        // 从叶子再调用下面的return的话，一定是false。均为nullptr

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};