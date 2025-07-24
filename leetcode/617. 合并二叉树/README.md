# [617. 合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)



## 题目

给你两棵二叉树： `root1` 和 `root2` 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，**不为** null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

**注意:** 合并过程必须从两个树的根节点开始。

 

**示例 1：**

![img](./assets/merge.jpg)

```
输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
输出：[3,4,5,5,4,null,7]
```

**示例 2：**

```
输入：root1 = [1], root2 = [1,2]
输出：[2,2]
```

 

**提示：**

- 两棵树中的节点数目在范围 `[0, 2000]` 内
- $-10^4 <= Node.val <= 10^4$



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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // 分情况讨论
        // 1. 二者都为空
        if (!(root1 || root2))
            return nullptr;
        // 2. 一个为空而另一个还存在。
        // 我以1为基准，把2多的加到1上
        if (root1 && !root2) // 1不为空 2为空
            return root1;

        if (!root1 && root2)
            return root2;

        // 3. 二者都存在节点，分别遍历他们的左右子树就可以
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
```





## points

1. 先写递归的终止条件，需要分情况进行讨论

   - 当root1, root2二者都为空时。返回nullptr，不做任何操作。传给上面的还是保留根节点
   - 当root1存在，root2为空时，应该保留1的节点，不管2的，因此无操作，但是返回root1
   - 当root1不存在，root2存在时，return root2

2. 下面只剩下一种情况，就是二者的节点都存在，这个时候先合并二者节点的值，以root1为基准

   之后分别遍历二者的左、右子树，把返回值均返回给 root1对应的左和右

   最终返回root1