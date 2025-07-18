# [129. 求根节点到叶节点数字之和](https://leetcode.cn/problems/sum-root-to-leaf-numbers/)



## 题目

给你一个二叉树的根节点 `root` ，树中每个节点都存放有一个 `0` 到 `9` 之间的数字。

每条从根节点到叶节点的路径都代表一个数字：

- 例如，从根节点到叶节点的路径 `1 -> 2 -> 3` 表示数字 `123` 。

计算从根节点到叶节点生成的 **所有数字之和** 。

**叶节点** 是指没有子节点的节点。

 

**示例 1：**

![img](./assets/num1tree.jpg)

```
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
```

**示例 2：**

![img](./assets/num2tree.jpg)

```
输入：root = [4,9,0,5,1]
输出：1026
解释：
从根到叶子节点路径 4->9->5 代表数字 495
从根到叶子节点路径 4->9->1 代表数字 491
从根到叶子节点路径 4->0 代表数字 40
因此，数字总和 = 495 + 491 + 40 = 1026
```

 

**提示：**

- 树中节点的数目在范围 `[1, 1000]` 内
- `0 <= Node.val <= 9`
- 树的深度不超过 `10`



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
    int sumNumbers(TreeNode *root, int x = 0)
    {
        if (!root)
            return 0;
        x = x * 10 + root->val;
        if (!(root->left || root->right))
            return x;
        return sumNumbers(root->left, x) + sumNumbers(root->right, x);
        // 该x是从上往下进行累加的结果，需要传入下面的
        // 在该函数的外部调用sumNumbers，不传入x是没问题的，是参数默认值
    }
};
```





## points

1. 值得注意的是需要处理每一层节点的权值。考虑直接从上往下开始加，每次到下一层，之前累加的值就*10。到达叶子节点的时候，恰好为个位，直接返回

2. 为了不断*10来得到真实的值，应该从上往下走，这样前面的数字可以一直被不断地变成10倍

3. 深度优先

   每次到一个非空节点的时候，给已经记录的值*10，并将当前节点的值加上，从而得到 到目前为止的值

   计算完成后，如果本节点是叶子节点，就直接返回了

   如果不是，还有子树，就左右两边分别递归，并加和。这样对于以后他们深度到底是是多少，是不关心的，从而确保了位数的正确性。

   而若任意一个为空，也会返回0