# [111. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)



## 题目

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

**说明：**叶子节点是指没有子节点的节点。

 

**示例 1：**

![img](./assets/ex_depth.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：2
```

**示例 2：**

```
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
```

 

**提示：**

- 树中节点数的范围在 $[0, 10^5]$ 内
- `-1000 <= Node.val <= 1000`



## 题目

解1

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
    int minDepth(TreeNode *root)
    {
        // 边界条件：root指针为nullptr
        if (!root)
            return 0;
        if (!root->left)
            return minDepth(root->right) + 1;
        if (!root->right)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    };
};
```



解2

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
    int minDepth(TreeNode *root)
    {
        // 分类讨论
        // 1. 空
        if (!root)
            return 0;
        // 2. 叶子
        if (!(root->left || root->right))
            return 1;
        // 3. 有左或右子树，如果没有，就记为∞，防止误判
        int left = root->left ? minDepth(root->left) : INT_MAX;
        int right = root->right ? minDepth(root->right) : INT_MAX;

        return min(left, right) + 1;
    };
};
```





## points

1. 最大深度会自动忽略掉如果没有叶子结点的情况，因为求的是最大

   但是最小深度需要注意，一定要确保是有叶子结点的那一边

2. 如果是叶子结点，左右子树都没有，那就会优先进入求右子树的深度并+1，而右子树也不存在，所以是0，因此叶子结点直接返回1

3. 注意取min的条件是：左右子树都不为0。这样确保不会误判。注意一定只有是叶子结点的时候，才+1计算深度

4. 解2分类进行讨论，同样注意规避掉误判的可能性