# [100. 相同的树](https://leetcode.cn/problems/same-tree/)



## 题目

给你两棵二叉树的根节点 `p` 和 `q` ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

 

**示例 1：**

![img](./assets/ex1.jpg)

```
输入：p = [1,2,3], q = [1,2,3]
输出：true
```

**示例 2：**

![img](./assets/ex2.jpg)

```
输入：p = [1,2], q = [1,null,2]
输出：false
```

**示例 3：**

![img](./assets/ex3.jpg)

```
输入：p = [1,2,1], q = [1,1,2]
输出：false
```

 

**提示：**

- 两棵树上的节点数目都在范围 `[0, 100]` 内
- $-10^4 <= Node.val <= 10^4$



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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
            return p == q;

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```





## points

1. 如果有节点为空，则必须停止递归。

   在这个情况下，必须p，q同时为空才可以，判断二者相等即可

   若有一个为空而另一个不为空，则return false，所以用p==q表达式的返回值来做区分即可

2. 接下来判断二者节点的值是否相等，如果不相等直接return false

   然后分别递归判断二者的左右子树是否相等，若任意不相等就直接return false

3. 2.的三点结合起来，就直接写一个&&的长表达式，因为需要三者都同时满足才算相等，否则任意一个条件：值、结构 不对应相等，就直接false