# [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)



## 题目

给定一个二叉树 `root` ，返回其最大深度。

二叉树的 **最大深度** 是指从根节点到最远叶子节点的最长路径上的节点数。

 

**示例 1：**

![img](./assets/tmp-tree.jpg)

 

```
输入：root = [3,9,20,null,null,15,7]
输出：3
```

**示例 2：**

```
输入：root = [1,null,2]
输出：2
```

 

**提示：**

- 树中节点的数量在 $[0, 10^4]$ 区间内。
- `-100 <= Node.val <= 100`



## 题解

- 时间复杂度：O(n)
- 空间复杂度：O(n)。最坏情况只有一个子树，则链状

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
public:
    int maxDepth(TreeNode *root)
    {
        // 边界条件：root指针为nullptr
        if (!root)
            return 0;
        int right = maxDepth(root->right);
        int left = maxDepth(root->left);
        return max(right, left) + 1;
    };
}
```





## points

1. 自底向上。自顶向下
1. 本题采取自底向上方法，即先一步步递归找到最深的叶子结点，从这里才开始计数，return 0，之后一步步+1