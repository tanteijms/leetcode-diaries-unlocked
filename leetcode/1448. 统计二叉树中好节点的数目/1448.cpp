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
    int goodNodes(TreeNode *root, int max = INT_MIN)
    {
        // 在递归的过程中，维护一个当前路径下的最大值，这样可以方便进行比较
        // 好节点的要求是到他的路径上，所有的节点的数都小于等于它自身
        // 因此维护一个最大值的量是合理的
        // INT_MIN是int的最小值，根据位数来决定
        if (!root)
            return 0; // 空节点直接跳过，返回0不影响结果
        // 这里需要针对有值的节点来更新这个max
        if (root->val > max)
            max = root->val;
        if (!(root->left || root->right))
        {
            if (max <= root->val) // 当前值就是最大的
                return 1;
            else // max比当前叶子节点的值要大
                return 0;
        }
        // 下面看非叶子节点
        if (max <= root->val) // 根据max和当前节点的值来区分最后是否+1
            return goodNodes(root->left, max) + goodNodes(root->right, max) + 1;
        else
            return goodNodes(root->left, max) + goodNodes(root->right, max);
    }
};