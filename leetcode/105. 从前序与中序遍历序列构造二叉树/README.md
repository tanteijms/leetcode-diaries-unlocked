# [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)



## 题目

给定两个整数数组 `preorder` 和 `inorder` ，其中 `preorder` 是二叉树的**先序遍历**， `inorder` 是同一棵树的**中序遍历**，请构造二叉树并返回其根节点。

 

**示例 1:**

![img](./assets/tree.jpg)

```
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
```

**示例 2:**

```
输入: preorder = [-1], inorder = [-1]
输出: [-1]
```

 

**提示:**

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `-3000 <= preorder[i], inorder[i] <= 3000`
- `preorder` 和 `inorder` 均 **无重复** 元素
- `inorder` 均出现在 `preorder`
- `preorder` **保证** 为二叉树的前序遍历序列
- `inorder` **保证** 为二叉树的中序遍历序列



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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 前序的第0号元素是根节点
        // 中序的第0号元素是最最左下角的结点
        // 那么可以知道，中序的根节点左边的，都是左子树的
        // 中序根节点右边的，都是右子树的
        // 而本题显然可以用递归做，找到左右子树后，就简化了问题

        if (preorder.empty())
            return nullptr;
        int left_size = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> pre2(preorder.begin() + 1 + left_size, preorder.end());
        vector<int> in1(inorder.begin(), inorder.begin() + left_size);
        vector<int> in2(inorder.begin() + 1 + left_size, inorder.end()); // 跳过根节点
        TreeNode *left = buildTree(pre1, in1);
        TreeNode *right = buildTree(pre2, in2);
        return new TreeNode(preorder[0], left, right);
    }
};
```



## points

1. 暴力O(n^2)做法。基本思路为，考虑递归，每次不断简化问题。因为我们可以知道，前序遍历的第一个结点，一定是当前子树的根节点，那么，为了简化问题，我们可以想办法找到当前子树的左右子树，并不断递归调用，即可不断简化问题

2. 所以问题就转化为了，当拿到一颗子树的中序和前序遍历时，如何定位得到它的左右子树。

   首先前序的第一个元素是当前根节点。

   然后，中序遍历因为是左 中 右，那么当我们在中序遍历中找到根节点的时候，那么显然，左边的部分都是左子树，右边的部分都是右子树

   而由于这个前序和中序都是针对同一颗子树的，所以我们可以在中序遍历的数组里确定左子树的大小范围，然后对两个数组进行切割

   前序：第一个是根。第二个到第left_size+1个是左子树，第left_size+2到end是右子树

   中序：前left_size个是左，left_size+1是根，后面的是右子树

   我们处理好这四个小的数组，就可以分别对左右子树调用build函数自身，然后不断递归。

   之后处理自身结点，创建当前的根节点root，赋值，然后左右分别指向left和right的返回值即可

3. 时间复杂度：O(n^2)。首先遍历所有的结点，也就是访问其值来构造结点；其次在遍历每一个结点的时候，都使用了find来确定根节点在中序遍历中的位置。

   空间复杂度：O(n)。栈递归空间，以及分割成不同的子树数组



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
    unordered_map<int, int> in_idx;

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int lpre, int rpre, int lin, int rin)
    {
        if (lpre == rpre) // 左闭右开，l=r应该是空区间了
            return nullptr;
        int root = in_idx[preorder[lpre]] - lin;
        TreeNode *left = dfs(preorder, inorder, lpre + 1, lpre + 1 + root, lin, lin + root);
        TreeNode *right = dfs(preorder, inorder, lpre + 1 + root, rpre, lin + root + 1, rin);
        return new TreeNode(preorder[lpre], left, right);
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 对于解1的优化，可以始终对同一个数组进行操作，省去每次构造新的数组
        // 以及可以把所有根节点，也就是前序的第一个，因为原来要去中序O(n)查找
        // 可以把中序处理成一个哈希表
        // 每次需要前序的根节点的时候，直接能在哈希表找到中序的下标号
        for (int i = 0; i < preorder.size(); i++)
            in_idx[inorder[i]] = i; // 预存inorder所有元素其对应的下标
        // 这样当我们从pre获得root结点的值时，可以直接在in_idx里
        // 找到在原inorder数组的位置，方便计算左右子树的大小
        return dfs(preorder, inorder, 0, preorder.size(), 0, preorder.size());
    }
};
```



1. 为了进行优化，考虑1.可以把每次获取root以后，因为要去中序里找对应位置，从而区分左右子树的大小，这个可以提前用一个哈希表，用结点值->下标的映射存储起来，可以很方便的取到  2.因为解1需要每次都创建新的数组，造成开辟大量空间，因此就在原数组上进行操作，用指针来标记左右区间起始，递归的时候传引用

2. 定义一个私有的哈希表，类内全局

3. 定义dfs函数，做后序遍历。对于每一个结点，首先判断当前结点是不是一个有效的结点，即是否非空。因为我们每次都是获取当前子区间内的根节点，也就是当前前序子区间的第一个值，因此我们判断前序区间是否存在。统一采用左闭右开，因此如果lpre=rpre，就是空区间，没有值，这里返回nullptr，递归停止

   若不为空，说明有当前结点。利用哈希表把当前根结点，也就是前序的第0号元素，找到这个值对应在中序遍历里的位置，这样得到左右子树的大小。

   然后分别递归调用，得到左右子树的根节点。因为我们可得到root是根结点的位置，则传给左子树的，前序：从lpre+1到lpre+1+root（左闭右开）。中序：从lin到lin+root.

   传给右子树：前序：从lpre+1+root，到rpre。中序：从lin+1+root(要跳过中间的根结点)，到rin

   然后new一个新节点，值是preorder的当前区间第一个值，左右子树分别是下层递归返回上来的，然后return给上层递归

4. 进入主函数，首先处理一下，对inorder进行遍历，其每一个元素，映射到其当前的下表上，存入哈希表

5. 直接调用dfs，从根节点开始，范围都是0~n，并且传引用传入两个数组
