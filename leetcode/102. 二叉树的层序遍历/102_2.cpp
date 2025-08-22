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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *top = q.front();
                temp.emplace_back(top->val);
                if (top->left)
                    q.emplace(top->left);
                if (top->right)
                    q.emplace(top->right);
                q.pop();
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};