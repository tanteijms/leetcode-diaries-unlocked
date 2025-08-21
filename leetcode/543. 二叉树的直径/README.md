# [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/)



## 题目

给你一棵二叉树的根节点，返回该树的 **直径** 。

二叉树的 **直径** 是指树中任意两个节点之间最长路径的 **长度** 。这条路径可能经过也可能不经过根节点 `root` 。

两节点之间路径的 **长度** 由它们之间边数表示。

 

**示例 1：**

![img](./assets/diamtree.jpg)

```
输入：root = [1,2,3,4,5]
输出：3
解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
```

**示例 2：**

```
输入：root = [1,2]
输出：1
```

 

**提示：**

- 树中节点数目在范围 $[1, 10^4]$ 内
- `-100 <= Node.val <= 100`



## 题解

```cpp
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
    int ans;

    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
```





## points

数的dp

递归，子问题和原问题的相似性，动态规划



1. 定义一个全局的ans，用来不断更新找到更大的值

2. 定义一个dfs，深度优先遍历

   在遍历的时候：

   若遇到空结点，直接返回0

   若非空，就分别递归左右子树，并记录值（若不记录，多次递归可能导致超时）

   然后用当前的答案与left+right进行比对，保留更大的

   return left和right更大的值，并+1（本结点）

3. 非空结点的return方式，选取左右子树更大的那个，并+1。这就决定了我们ans是正确更新的

   每次都从返回给上一层更大的结果，保证结果也是最大的