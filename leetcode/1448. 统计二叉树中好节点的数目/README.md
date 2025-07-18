# [1448. 统计二叉树中好节点的数目](https://leetcode.cn/problems/count-good-nodes-in-binary-tree/)



## 题目

给你一棵根为 `root` 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

 

**示例 1：**

**![img](./assets/test_sample_1.png)**

```
输入：root = [3,1,4,3,null,1,5]
输出：4
解释：图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -> (3,4) 是路径中的最大值。
节点 5 -> (3,4,5) 是路径中的最大值。
节点 3 -> (3,1,3) 是路径中的最大值。
```

**示例 2：**

**![img](./assets/test_sample_2.png)**

```
输入：root = [3,3,null,4,2]
输出：3
解释：节点 2 -> (3, 3, 2) 不是好节点，因为 "3" 比它大。
```

**示例 3：**

```
输入：root = [1]
输出：1
解释：根节点是好节点。
```

 

**提示：**

- 二叉树中节点数目范围是 $[1, 10^5]$ 。
- 每个节点权值的范围是 $[-10^4, 10^4]$ 。



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
    int goodNodes(TreeNode *root, int max = INT_MIN)
    {
        // 在递归的过程中，维护一个当前路径下的最大值，这样可以方便进行比较
        // 好节点的要求是到他的路径上，所有的节点的数都小于等于它自身
        // 因此维护一个最大值的量是合理的
        // INT_MIN是int的最小值，根据位数来决定
        if (!root)
            return 0; // 空节点直接跳过，返回0不影响结果
        // 这里需要针对有值的节点来更新这个max
        if (root->val > max)
            max = root->val;
        if (!(root->left || root->right))
        {
            if (max <= root->val) // 当前值就是最大的
                return 1;
            else // max比当前叶子节点的值要大
                return 0;
        }
        // 下面看非叶子节点
        if (max <= root->val) // 根据max和当前节点的值来区分最后是否+1
            return goodNodes(root->left, max) + goodNodes(root->right, max) + 1;
        else
            return goodNodes(root->left, max) + goodNodes(root->right, max);
    }
};
```







## points

1. 这题重要的一点是如何确定当前节点是从根节点到达自身这一整条路径上，最大的值。因此可以在递归的过程中维护一个max值，用来记录从根开始的当前路径上的最大值。每次遇到有值的节点，都需要去比较并更新这个max

   剩下的操作就是正常的递归，分节点情况进行讨论

2. 我写的是个后序遍历，先得到子树的值，再根据自身的情况判断是否+1