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
    int ans = 0;
    unordered_map<long long, int> cnt{{0, 1}};
    // 需要对最开始，前缀和为0的做一个记录，值为1
    // 这样若前缀和恰好就是遍历到的结点的值，这样可以直接targetSum就是起点到这个结点

    void dfs(TreeNode *node, long long s, int targetSum)
    {
        if (!node)
            return;
        s += node->val;            // 统计前缀和
        ans += cnt[s - targetSum]; // 对于每一个结点，都要先统计答案值，再存入哈希表
        // 比如若targetSum=0，如果先cnt[s]++，就多了一个自己结点，这样不存在路径
        cnt[s]++;
        dfs(node->left, s, targetSum);
        dfs(node->right, s, targetSum);
        cnt[s]--;
        // 除掉当前结点，因为要结束当前结点递归向上返回了，其余路径不应该包含此结点
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, 0, targetSum);
        return ans;
    }
};