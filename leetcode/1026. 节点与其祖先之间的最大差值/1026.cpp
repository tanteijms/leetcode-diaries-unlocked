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
    int fun(TreeNode *root, int big, int small)
    {
        // 用big和small记录该路径的最大值与最小值
        // 初始在主函数调用的时候传入root指向的val
        // 1. 为空
        if (!root)
            return 0; // return啥呢。因为求的是最大，所以return 0不会影响
        // 2. 非空，有值，就需要去更新big和small
        big = max(root->val, big);
        small = min(root->val, small);

        // 叶子。叶子其实都不用单独考虑，因为如果子树为空的话就return 0了
        // 不影响最后的max结果
        // if (!(root->left || root->right))
        //    return big - small;

        return max({big - small, fun(root->left, big, small), fun(root->right, big, small)});
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        return fun(root, root->val, root->val);
    }
};