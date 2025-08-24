# [114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)



## 题目

给你二叉树的根结点 `root` ，请你将它展开为一个单链表：

- 展开后的单链表应该同样使用 `TreeNode` ，其中 `right` 子指针指向链表中下一个结点，而左子指针始终为 `null` 。
- 展开后的单链表应该与二叉树 [**先序遍历**](https://baike.baidu.com/item/先序遍历/6442839?fr=aladdin) 顺序相同。

 

**示例 1：**

![img](img/README/flaten.jpg)

```
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
```

**示例 2：**

```
输入：root = []
输出：[]
```

**示例 3：**

```
输入：root = [0]
输出：[0]
```

 

**提示：**

- 树中结点数在范围 `[0, 2000]` 内
- `-100 <= Node.val <= 100`

 

**进阶：**你可以使用原地算法（`O(1)` 额外空间）展开这棵树吗？



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
    vector<TreeNode *> nodes;

    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        nodes.emplace_back(node);
        dfs(node->left);
        dfs(node->right);
    }

public:
    void flatten(TreeNode *root)
    {
        // 先写数组存储结点实现
        dfs(root);
        if (nodes.empty())
            return;
        root = nodes[0];
        TreeNode *cur = root;
        for (int i = 1; i < nodes.size(); i++)
        {
            cur->right = nodes[i];
            cur->left = nullptr;
            cur = nodes[i];
        }
    }
};
```





## points

1. 先考虑简单做法，即对这个二叉树进行前序遍历，然后按照前序的顺序把所有的结点存储到一个vector数组里

2. 之后在主循环里，从root开始，将右节点设置为其原来二叉树前序遍历的直接后继，这样就展平成了一个链状的

   不过注意，因为结点类型还是二叉树，所以要同步把每一个结点的左子树，设置为nullptr



## 解2

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
    TreeNode *head = nullptr;

public:
    void flatten(TreeNode *root)
    {
        // 原地构造，不要有额外的空间开辟
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};
```





1. 考虑顺序。题目要求的是按照前序遍历，而我们可以用后序遍历+头插法，这样恰好得到的顺序就是题目所求的

2. 直接利用主函数进行递归。

   首先判断递归终止条件，若为空，直接return

   下面按照后序遍历：

   先右子树，然后左子树

   最后处理本结点，给left子树设为nullptr，right子树设为当前head，这样就能够在当前head的前面插入当前的结点了。之后要更新head为当前遍历到的结点，从而能够一直保持在最前



## 解3

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
    TreeNode *dfs(TreeNode *node)
    {
        if (!node)
            return nullptr;
        TreeNode *left = dfs(node->left);
        TreeNode *right = dfs(node->right);
        // 两子树都处理完了，下面开始拼接
        // 注意这个left有可能是nullptr，所以要判断一步
        if (left)
        {
            left->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        TreeNode *result = (right ? right : (left ? left : node));
        return result;
    }

public:
    void flatten(TreeNode *root)
    {
        dfs(root);
    }
};
```





1. 如果不用类内成员遍历的head，可以直接在遍历结点的时候进行操作

2. 考虑当我们遍历到某一个结点的时候，该如何操作：

   首先让左子树变为链式

   其次将右子树变为链式

   那么，当前结点及以下的部分，就只需要进行穿针引线。因为两子树都已经分别处理完了，那么，就先把左子树的最后一个结点，让他的right指向右子树的第一个。然后，将当前结点的right，设为左子树的第一个结点。然后，将当前结点的left，设为nullptr。

3. 为此，我们需要找到左子树的最后一个结点，才能够完成当前的拼接。那么在设计返回值的时候，下层函数要给上层函数返回自己的拼接好的最后一个结点，那么在下层递归的时候，如何得到自己的最后一个结点呢？

   首先最后的应该是右子树的最后的；

   但是也有可能下层递归根本没有右子树，那么就返回左子树的最后的；

   但是也有可能，下层递归也没有左子树，那么就返回当前结点即可

4. 注意在穿针引线的时候，如果排序好的左子树根本不存在，那么说明目前的就直接是left为nullptr，且right为后面的结点，也就是不需要操作
