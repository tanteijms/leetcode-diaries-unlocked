# [199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)



## 题目

给定一个二叉树的 **根节点** `root`，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

 

**示例 1：**

**输入：**root = [1,2,3,null,5,null,4]

**输出：**[1,3,4]

**解释：**

![img](./assets/tmpd5jn43fs-1.png)

**示例 2：**

**输入：**root = [1,2,3,4,null,null,null,5]

**输出：**[1,3,4,5]

**解释：**

![img](./assets/tmpkpe40xeh-1.png)

**示例 3：**

**输入：**root = [1,null,3]

**输出：**[1,3]

**示例 4：**

**输入：**root = []

**输出：**[]

 

**提示:**

- 二叉树的节点个数的范围是 `[0,100]`
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
    vector<int> ans = {};
    void fun(TreeNode *node, int depth)
    {
        if (!node)
            return;
        if (depth == ans.size())
            ans.push_back(node->val);
        fun(node->right, depth + 1);
        fun(node->left, depth + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        fun(root, 0);
        return ans;
    }
};
```





## points

1. 在递归的过程中，记录一个深度值，初始为0，只有当深度和答案长度相等的时候，把当前节点加入到答案的末尾
2. 先递归右子树，再递归左子树，每个节点处判断深度和答案的长度大小关系，是否添加当前节点值