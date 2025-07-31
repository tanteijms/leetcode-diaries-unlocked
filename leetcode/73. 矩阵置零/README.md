# [73. 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/)



## 题目

给定一个 `*m* x *n*` 的矩阵，如果一个元素为 **0** ，则将其所在行和列的所有元素都设为 **0** 。请使用 **[原地](http://baike.baidu.com/item/原地算法)** 算法**。**

 

**示例 1：**

![img](./assets/mat1.jpg)

```
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
```

**示例 2：**

![img](./assets/mat2.jpg)

```
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

 

**提示：**

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- $-2^{31} <= matrix[i][j] <= 2^{31} - 1$



## 题解

```cpp
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> st; // 可以去重
        for (int i = 0; i < matrix.size(); i++)
        {
            int flag = 0; // 用来指示当前行是否有0
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    flag = 1;
                    st.insert(j);
                }
            }
            if (flag)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (st.count(i))
            {
                for (int j = 0; j < matrix.size(); j++)
                    matrix[j][i] = 0;
            }
        }
    }
};
```



## points

1. 首先行优先遍历整个矩阵，在每一行遍历的过程中，设立一个变量flag，用来记录当前行是否含有0元素，这是在对该行的每一列遍历的过程中判断的。同时，如果该行中找到了某一列是0，就要记录下来这个列的索引，以便在后面可以对列进行修改。

   对列号的记录采取了unordered_set，可以自动去重，使用.insert()方法插入列号。最坏的空间复杂度为O(n)，即列的总长度

2. 每一行可能需要遍历两次列，也就是如果flag为1，说明本行中有0元素，那么就需要把该行所有元素置零。

3. 之后跳出遍历整个矩阵的循环。下面按照列优先进行遍历，对于每一列，用st去判断它的索引号是否在st里，如果在，那就遍历这个列，然后置零