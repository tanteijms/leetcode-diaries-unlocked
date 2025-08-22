# [102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)



## 题目

给你二叉树的根节点 `root` ，返回其节点值的 **层序遍历** 。 （即逐层地，从左到右访问所有节点）。

 

**示例 1：**

![img](./assets/tree1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
```

**示例 2：**

```
输入：root = [1]
输出：[[1]]
```

**示例 3：**

```
输入：root = []
输出：[]
```

 

**提示：**

- 树中节点数目在范围 `[0, 2000]` 内
- `-1000 <= Node.val <= 1000`



## 题解

- 时间复杂度：O(n)。遍历二叉树的所有结点
- 空间复杂度：O(n)。当是满二叉树时，最后一层的结点个数逼近n/2，且维护了cur和nxt两个数组。因此是n规模的

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<TreeNode *> cur = {root};
        while (!cur.empty())
        {
            vector<int> temp;
            vector<TreeNode *> nxt;
            for (int i = 0; i < cur.size(); i++)
            {
                temp.emplace_back(cur[i]->val);
                if (cur[i]->left)
                    nxt.emplace_back(cur[i]->left);
                if (cur[i]->right)
                    nxt.emplace_back(cur[i]->right);
            }
            cur = nxt;
            ans.emplace_back(temp);
        }
        return ans;
    }
};
```



时空复杂度同上

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *top = q.front();
                temp.emplace_back(top->val);
                if (top->left)
                    q.emplace(top->left);
                if (top->right)
                    q.emplace(top->right);
                q.pop();
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};
```





## points

1. 广度优先搜索，层序遍历

2. 双数组方法

   维护cur和nxt数组，cur存当前层的所有结点，nxt存遍历cur的所有子树，如果有就存

   添加完cur的值以后，cur更新为nxt，然后继续

   最后当cur为空的时候，结束

   解法：

   首先判断二叉树是否非空，如果为空直接return {}

   初始化ans数组

   初始化cur数组为root一个元素

   下面进入循环，循环的结束条件为cur为空，即遍历完了所有的二叉树结点

   注意C++里用的是.empty()

   每次循环，初始化本层的答案数组

   初始化nxt数组，由于nxt是每一层更新的，所以直接每次重新声明即可，后续用emplace_back

   下面遍历cur数组，对于取到的每一个结点

   首先记录值

   然后加入非空的子树

   这里可以看到，我们每次都确保了nxt里不会有nullptr，而初始root不会是nullptr，因此cur始终都是有效的指针，因此记录值的时候可以直接放心使用，不会非法访问

   遍历完cur内所有结点后，把cur更新为nxt，进入下一层

   同时把本层的答案加入到总的ans里

3. 维护一个数组，层序遍历，用队列

4. 同样先判断二叉树是否为空，若空直接return {}

   初始化ans

   初始化queue的q，类型是结点TreeNode*

   注意queue不能在构造函数的时候直接插入值，需要先声明，然后用push

   这里全采用了emplace，效率更高

   进入循环，退出条件是q为空时

   初始化temp数组，记录本层的答案值

   这里需要把q当前的个数直接取出来，因为q的size()是实时变化的

   进入当前层的循环，遍历当前层的所有结点

   省事，把q的front提取出来为top

   把本层结点的值存入temp

   然后判断是否有左右子树，有则存入

   处理完后，pop队列头，不需要了

   处理完本层后，将temp加入到ans

   