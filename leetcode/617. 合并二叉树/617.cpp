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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // 分情况讨论
        // 1. 二者都为空
        if (!(root1 || root2))
            return nullptr;
        // 2. 一个为空而另一个还存在。
        // 我以1为基准，把2多的加到1上
        if (root1 && !root2) // 1不为空 2为空
            return root1;

        if (!root1 && root2)
            return root2;

        // 3. 二者都存在节点，分别遍历他们的左右子树就可以
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};