# [110. 平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/)



## 题目

给定一个二叉树，判断它是否是 平衡二叉树 

 

**示例 1：**

![img](./assets/balance_1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：true
```

**示例 2：**

![img](./assets/balance_2.jpg)

```
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
```

**示例 3：**

```
输入：root = []
输出：true
```

 

**提示：**

- 树中的节点数在范围 `[0, 5000]` 内
- <code>-10<sup>4</sup> <= Node.val <= 10<sup>4</sup></code>



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
    int getHeight(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = getHeight(node->left);
        if (left == -1)
            return -1;
        int right = getHeight(node->right);
        if (right == -1 || abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) != -1;
    }
};
```





## points

1. 平衡二叉树的要求是对任意一个节点，它的左子树高度 和 右子树高度之差不超过1。因此可以先写一个递归求左右子树高度的函数，递归调用它
2. 对于递归的返回值，我们让他返回左右子树中更大的那个，并且再算上自身节点，即+1。上一层的树在收到返回值以后，进行自己两棵子树的判断，如果平衡，就继续向上返回更大的高度值+1。
3. 这时我们可以发现，只要是平衡的，那么递归返回的都是高度值，都是正数。那么如果不平衡，可以返回-1，每次每个节点先看是否是-1，如果下级的返回值有-1，就直接return -1，把这个-1逐级向上最终返回到根节点。根节点最后再去判断