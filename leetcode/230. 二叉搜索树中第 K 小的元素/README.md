# [230. 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/)



## 题目

给定一个二叉搜索树的根节点 `root` ，和一个整数 `k` ，请你设计一个算法查找其中第 `k` 小的元素（从 1 开始计数）。

 

**示例 1：**

![img](img/README/kthtree1.jpg)

```
输入：root = [3,1,4,null,2], k = 1
输出：1
```

**示例 2：**

![img](img/README/kthtree2.jpg)

```
输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
```

 

 

**提示：**

- 树中的节点数为 `n` 。
- $1 <= k <= n <= 10^4$
- $0 <= Node.val <= 10^4$

 

**进阶：**如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 `k` 小的值，你将如何优化算法？



## 题解

- 时间复杂度：O(n)。第一次遍历所有节点，第二次主函数内进行排序，n log n。
- 空间复杂度：O(n)。使用了 vector 数组来存储二叉树所有节点。

`````cpp
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
class Solution {
    vector<int> all;

    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        
        all.emplace_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        sort(all.begin(), all.end());
        return all[k - 1];
    }
};
`````



## points

1. 使用一个 vector 数组，在前序遍历深度优先搜索的时候，遍历所有节点并记录所有的值，递归到为空时终止
2. 在主函数里对数组进行排序，然后返回要的第 k 小的
3. 这种暴力做法没有用到二叉搜索树的特点



## 解2

```c++
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
class Solution {
    int ans;

    void dfs(TreeNode* node, int &k)
    {
        if(!node || k == 0)
            return;

        dfs(node->left, k);

        k--;
        if(k == 0)
            ans = node->val;

        dfs(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};
```



1. 定义一个全局的 ans，用来存储递归过程中的答案
2. 定义 dfs 函数，传入当前结点，以及递归过程中维护的 k 值。本题的思路这样，因为二叉搜索树所有结点本身天然满足左子树<当前<右子树，因此我们使用中序遍历，每次先遍历左边的，那么显然就是从最小的开始的。因为我们要找的是第 k 小的，找到的第一个结点，显然是第 1 小的，那么当我们递归到第 k 次的时候，显然是第 k 小的。因此，我们在递归的时候直接把 k 值传入进去，并进行每次访问当前结点，就 k--。这样就能很好的控制递归到底该何时结束。不过要注意的就是，这里 k 需要传引用，否则无法正确维护 k
3. 递归结束条件为，要么访问到空结点，直接返回；要么当前 k 值已经归零，那么说明 ans 已经找到了第 k 小的值，则结束
4. 当非空时，中序遍历即可。对于本结点，先给 k--，然后判断 k 是否为 0，若为零，就把 ans 正确赋值 
5. 主函数只要调用 dfs(root)，然后直接返回 ans 即可



## 解3

```c++
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
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root)
            return -1;
        int left = kthSmallest(root->left, k);
        if(left!=-1)
            return left;
        k--;
        if(k==0)
            return root->val;
        return kthSmallest(root->right, k);
    }
};
```



1. 解 2 维护了一个全局的 ans。可以直接用主函数本体直接进行递归，而免去了维护操作
2. 首先把主函数的 k 改为传入引用，这可以正确维护 k 值，且不会导致主程序崩坏
3. 因为题目说了结点的值为正，因此使用-1 来维护。若访问到空结点，返回-1。然后递归左子树，记录返回结果，进行判断，若为-1，说明还没有找到 ans。若不为-1，那么这个值就肯定被改变了，因此返回这个 left 值
4. 对于中间结点，先给 k--，然后判断是否为 0，为零，说明答案就是当前结点的值，因此直接返回这个值
5. 右子树，直接返回即可，因为右子树一定会返回左 中的值。要么是答案，要么是 -1。且题目确保了答案一定存在，则不会出错

