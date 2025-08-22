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
        if(!root)
        vector<vector<int>> ans;
        vector<TreeNode *> cur = {root};
        while (!cur.empty())
        {
            vector<int> temp;
            vector<TreeNode *> nxt;
            for (int i = 0; i < cur.size(); i++)
            {
                temp.emplace_back(cur[i]->val);
                if (cur[i]->left)
                    nxt.emplace_back(cur[i]->left);
                if (cur[i]->right)
                    nxt.emplace_back(cur[i]->right);
            }
            cur = nxt;
            ans.emplace_back(temp);
        }
        return ans;
    }
};