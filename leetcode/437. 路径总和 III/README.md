# [437. 路径总和 III](https://leetcode.cn/problems/path-sum-iii/)



## 题目

给定一个二叉树的根节点 `root` ，和一个整数 `targetSum` ，求该二叉树里节点值之和等于 `targetSum` 的 **路径** 的数目。

**路径** 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

 

**示例 1：**

![img](./assets/pathsum3-1-tree.jpg)

```
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
```

**示例 2：**

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
```

 

**提示:**

- 二叉树的节点个数的范围是 `[0,1000]`
- $-10^9 <= Node.val <= 10^9$ 
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
    int ans = 0;
    unordered_map<long long,int> cnt{{0,1}};
    // 需要对最开始，前缀和为0的做一个记录，值为1
    // 这样若前缀和恰好就是遍历到的结点的值，这样可以直接targetSum就是起点到这个结点

    void dfs(TreeNode *node, long long s, int targetSum)
    {
        if (!node)
            return;
        s += node->val;            // 统计前缀和
        ans += cnt[s - targetSum]; // 对于每一个结点，都要先统计答案值，再存入哈希表
        // 比如若targetSum=0，如果先cnt[s]++，就多了一个自己结点，这样不存在路径
        cnt[s]++;
        dfs(node->left, s, targetSum);
        dfs(node->right, s, targetSum);
        cnt[s]--;
        // 除掉当前结点，因为要结束当前结点递归向上返回了，其余路径不应该包含此结点
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        dfs(root,0,targetSum);
        return ans;
    }
};
```



## points

1. 本题的思路和给定一个数组，求某个区间加和等于target值是一样的，因为已知所有的数有正有负，因此不能滑动窗口。要用前缀和。不过与普通数组前缀和区别的点是，二叉树分成不同的路径，因此深度优先遍历的时候需要处理不同路径上的结点前缀和

2. 首先初始化全局变量ans为0

   然后初始化记录前缀和的哈希表，由于结点加和值可能超过int，因此用long long，而记录每一个前缀和的个数，就用int。初始化加入一个{0,1}。和前缀和一样，为了得到如果当前前缀和s=target值，这样起点到当前结点，就是所要的，路径+1

3. 下面定义dfs函数。需要传入当前遍历到的结点node，从起点的加和s，以及target值

   递归终止条件为，结点为空，直接return

   首先叠加前缀和s

   然后要先计算到当前结点，是否有答案。给哈希表传入s-target，如果不为0，说明前面的某个结点到当前结点，显然就是一条有效的路径

   然后再给哈希表记录当前前缀和的值。

   这样的顺序是为了保证，假设target恰好=0，可以保证不会误计算当前结点，一个结点不认为是路径

   然后分别递归左右子树

   最后注意要从哈希表中，给当前结点的s的值--，这样递归返回到上层结点了，不会计算当前结点的

4. 主函数直接调用dfs即可，返回ans