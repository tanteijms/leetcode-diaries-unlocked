class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *pre = nullptr;
        while (root)
        {
            if (root->left)
            {
                pre = root->left;
                while (pre->right && pre->right != root)
                    pre = pre->right;
                // 这里最终找到的pre是非空的结点才行，因此pre->right
                if (!pre->right)
                {
                    pre->right = root;
                    root = root->left; // 继续遍历左子树
                    // 相当于现在还在递归的递归的状态，else是回溯
                }
                else
                {
                    pre->right = nullptr;
                    ans.emplace_back(root->val);
                    root = root->right;
                }
            }
            else
            {
                ans.emplace_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};