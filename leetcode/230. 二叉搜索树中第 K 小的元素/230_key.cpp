class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if (node == nullptr || k == 0) {
                return;
            }
            dfs(node->left); // 左
            if (--k == 0) {
                ans = node->val; // 根
            }
            dfs(node->right); // 右
        };
        dfs(root);
        return ans;
    }
};