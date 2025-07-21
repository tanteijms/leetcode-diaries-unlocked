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
    // 不写private默认就是
    map<int, vector<pair<int, int>>> groups;

    void dfs(TreeNode *node, int row, int col)
    {
        if (node == nullptr)
            return;
        groups[col].emplace_back(row, node->val);
        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // 先dfs获取所有的组，按(col, row, val)为一组
        // 之后从第一列到最后一列，对同一col内(row, val)排序，先row后val
        // 按顺序把值粘贴到答案vector里
        // 最后返回的是一个序列
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto &[_, g] : groups)
        {
            ranges::sort(g);
            vector<int> vals;
            for (auto &[_, val] : g)
            {
                vals.push_back(val);
            }
            ans.push_back(vals);
        }
        return ans;
    }
};