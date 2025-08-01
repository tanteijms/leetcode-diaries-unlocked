# [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)



## 题目

编写一个高效的算法来搜索 `*m* x *n*` 矩阵 `matrix` 中的一个目标值 `target` 。该矩阵具有以下特性：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。

 

**示例 1：**

![img](./assets/searchgrid2.jpg)

```
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
```

**示例 2：**

![img](./assets/searchgrid.jpg)

```
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false
```

 

**提示：**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= n, m <= 300`
- $-10^9 <= matrix[i][j] <= 10^9$
- 每行的所有元素从左到右升序排列
- 每列的所有元素从上到下升序排列
- $-10^9 <= target <= 10^9$



## 题解

- 时间复杂度：O(m + n)。最坏情况是沿着对角线走，最多也就是m+n
- 空间复杂度：O(1)。仅用到若干变量

```cpp
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = 0, j = matrix[0].size() - 1;
        while (j >= 0 && i < matrix.size())
        {
            if (matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
            else
                return true;

            if (j == 0 && matrix[i][j] > target)
                return false;
        }
        return false;
    }
};
```





## points

1. 由于下一行不是严格大于上一行的，因此不能对行使用二分，因为只能找到target一定在某一行的上面（即这个行的第一个元素都大于target），但是无法确定是0到该行左闭右开的具体哪一行
2. 考虑从右上角开始遍历，如果当前元素大于target，就往左走；如果小于，就往下走。注意边界条件是ij不能越界，都要在0 m n的范围内。如果最终找到了，就return true；退出循环，就return false