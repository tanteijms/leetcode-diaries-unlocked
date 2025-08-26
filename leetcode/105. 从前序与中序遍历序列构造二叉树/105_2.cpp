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
    unordered_map<int, int> in_idx;

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int lpre, int rpre, int lin, int rin)
    {
        if (lpre == rpre) // 左闭右开，l=r应该是空区间了
            return nullptr;
        int root = in_idx[preorder[lpre]] - lin;
        TreeNode *left = dfs(preorder, inorder, lpre + 1, lpre + 1 + root, lin, lin + root);
        TreeNode *right = dfs(preorder, inorder, lpre + 1 + root, rpre, lin + root + 1, rin);
        return new TreeNode(preorder[lpre], left, right);
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 对于解1的优化，可以始终对同一个数组进行操作，省去每次构造新的数组
        // 以及可以把所有根节点，也就是前序的第一个，因为原来要去中序O(n)查找
        // 可以把中序处理成一个哈希表
        // 每次需要前序的根节点的时候，直接能在哈希表找到中序的下标号
        for (int i = 0; i < preorder.size(); i++)
            in_idx[inorder[i]] = i; // 预存inorder所有元素其对应的下标
        // 这样当我们从pre获得root结点的值时，可以直接在in_idx里
        // 找到在原inorder数组的位置，方便计算左右子树的大小
        return dfs(preorder, inorder, 0, preorder.size(), 0, preorder.size());
    }
};