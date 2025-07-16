# [112. 路径总和](https://leetcode.cn/problems/path-sum/)



## 题目

给你二叉树的根节点 `root` 和一个表示目标和的整数 `targetSum` 。判断该树中是否存在 **根节点到叶子节点** 的路径，这条路径上所有节点值相加等于目标和 `targetSum` 。如果存在，返回 `true` ；否则，返回 `false` 。

**叶子节点** 是指没有子节点的节点。

 

**示例 1：**

![img](./assets/pathsum1.jpg)

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。
```

**示例 2：**

![img](./assets/pathsum2.jpg)

```
输入：root = [1,2,3], targetSum = 5
输出：false
解释：树中存在两条根节点到叶子节点的路径：
(1 --> 2): 和为 3
(1 --> 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。
```

**示例 3：**

```
输入：root = [], targetSum = 0
输出：false
解释：由于树是空的，所以不存在根节点到叶子节点的路径。
```

 

**提示：**

- 树中节点的数目在范围 `[0, 5000]` 内
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`



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
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 1. 若为空
        if (!root)
            return false;
        // 2. 当前递归到的节点非空，处理与targetSum的关系
        targetSum -= root->val;
        // 3. 判断是否为叶子，如果是叶子，且恰好加和为0，直接返回true
        if (!(root->left || root->right) && targetSum == 0)
            return true; // 如果是叶子节点，但不满足条件，会进入下面的return
        // 从叶子再调用下面的return的话，一定是false。均为nullptr

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
```





## points

1. 使用自身递归即可。依次判断条件

   若为空，说明其父节点（叶子）不满足，则return false

   后面，就说明当前节点非空，因此需要给targetSum减去一个当前的val

   若为叶子，这里判断叶子需要左右子树都为空，因此应该对左右子树使用或非，这样只要有一个为非空，则整体判断为false，达到目的。当为叶子的时候，看一下targetSum是否归0。若为0，说明满足题意，return true

   再往下，说明要么是普通节点，要么该叶子结点不满足，则往下取找子节点即可。分别对左右子树进行递归调用，然后返回他们返回的结果的或，即若有一个为真，则该题目为true

2. 这题利用自身的递归调用自身即可，不必再写一个深度优先搜索