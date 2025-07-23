# [226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)



## 题目

给你一棵二叉树的根节点 `root` ，翻转这棵二叉树，并返回其根节点。

 

**示例 1：**

![img](./assets/invert1-tree.jpg)

```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

**示例 2：**

![img](./assets/invert2-tree.jpg)

```
输入：root = [2,1,3]
输出：[2,3,1]
```

**示例 3：**

```
输入：root = []
输出：[]
```

 

**提示：**

- 树中节点数目范围在 `[0, 100]` 内
- `-100 <= Node.val <= 100`



## 题解

- 时间复杂度：O(n)
- 空间复杂度：O(n)

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
    TreeNode *invertTree(TreeNode *root)
    {
        // 如果是空节点，return nullptr
        if (!root)
            return nullptr;

        // 如果是叶子节点，不用交换
        if (!(root->left || root->right))
            return root;

        // 先递归左右子树，再交换他们
        TreeNode *temp = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = temp;

        return root;
    }
};
```





## points

1. 分不同节点情况进行讨论

   若为空，返回nullptr

   若为叶子，不用交换，返回自身

   其余情况，递归调用左右子树，之后再交换

   最后返回自身

2. 优化：叶子、只有一棵子树，都可以优化进普通情况，因为已经写了如果是空就直接nullptr