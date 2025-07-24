# [1026. 节点与其祖先之间的最大差值](https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/)



## 题目

给定二叉树的根节点 `root`，找出存在于 **不同** 节点 `A` 和 `B` 之间的最大值 `V`，其中 `V = |A.val - B.val|`，且 `A` 是 `B` 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

 

**示例 1：**

![img](./assets/tmp-tree.jpg)

```
输入：root = [8,3,10,1,6,null,14,null,null,4,7,13]
输出：7
解释： 
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
```

**示例 2：**

![img](./assets/tmp-tree-1.jpg)

```
输入：root = [1,null,2,null,0,3]
输出：3
```

 

**提示：**

- 树中的节点数在 `2` 到 `5000` 之间。
- <code>0 <= Node.val <= 10<sup>5</sup></code>



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
    int fun(TreeNode *root, int big, int small)
    {
        // 用big和small记录该路径的最大值与最小值
        // 初始在主函数调用的时候传入root指向的val
        // 1. 为空
        if (!root)
            return 0; // return啥呢。因为求的是最大，所以return 0不会影响
        // 2. 非空，有值，就需要去更新big和small
        big = max(root->val, big);
        small = min(root->val, small);

        // 叶子。叶子其实都不用单独考虑，因为如果子树为空的话就return 0了
        // 不影响最后的max结果
        // if (!(root->left || root->right))
        //    return big - small;

        return max({big - small, fun(root->left, big, small), fun(root->right, big, small)});
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        return fun(root, root->val, root->val);
    }
};
```





## points

1. 因为要求一条路径上最大的差值，因此可以在递归的过程里，记录下来当前记录的最大值和最小值，并不断更新：每次遍历到一个新的节点，就进行比较，如果它比最大值更大，或者比最小值更小，那么就要更新递归一直传下来的big和small，得到一个更大的差值

2. 递归的终止条件：当节点为空时，直接return

   由于我们求的是最大值，因此在节点为空的时候return一个0，是不会影响后面求最大值的操作的

3. 当节点不为空的时候，就要根据当前节点的这个新的值，来对应更新big和small，进行判断

4. 之后返回三者的最大值：当前节点下的big-small，递归左子树得到的fun返回值，以及递归右子树得到的fun返回值。这三者取一个最大值，最后返回给上一级递归

5. 定义了fun这个新的函数去完成递归的操作。在solution的主函数里，只需要调用，并把big和small都赋为当前节点的值就可以了