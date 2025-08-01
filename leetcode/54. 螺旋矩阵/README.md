# [54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)



## 题目

给你一个 `m` 行 `n` 列的矩阵 `matrix` ，请按照 **顺时针螺旋顺序** ，返回矩阵中的所有元素。

 

**示例 1：**

![img](./assets/spiral1.jpg)

```
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
```

**示例 2：**

![img](./assets/spiral.jpg)

```
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
```

 

**提示：**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`



## 题解

- 时间复杂度：O(m * n)。需要遍历到矩阵的每一个元素
- 空间复杂度：O(1)。在原地进行修改，没有额外数组

```cpp
class Solution
{
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // 方向数组，0 1向右 1 0向下 0 -1向左 -1 0向上

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        int i = 0, j = 0, di = 0; // di用来表示当前的方向数组
        // i j等于0，从0, 0即左上角开始
        for (int k = 0; k < m * n; k++)
        {
            // 每次先添加，ij都是新的元素。添加以后对ij进行更新
            ans[k] = matrix[i][j]; // 添加后设为INT_MAX
            matrix[i][j] = INT_MAX;
            int x = i + DIRS[di][0]; // di指示当前的方向，只有在拐点才需要修改。最外圈用0和m n判断里面用INT_MAX
            int y = j + DIRS[di][1]; // 当前方向是什么，就给ij加多少来移动，对应方向数组的横和竖
            // 但是不能直接对ij进行加减，可能导致越界，因此先用x y临时变量去看，如果加上了di的方向，是否会到达边界
            // 或者是否到达已经访问过的
            // 如果是，那就对di进行更新，然后再更新i j
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MAX)
                di = (di + 1) % 4; // 方向数组总共4个方向
            i += DIRS[di][0];
            j += DIRS[di][1];
        }
        return ans;
    }
};
```





## points

1. 从矩阵左上角 `(0, 0)` 出发，按顺时针方向遍历所有元素。
   使用方向数组 `DIRS` 表示右、下、左、上四个方向，初始方向为右。每次循环：

   将当前位置 `matrix[i][j]` 加入答案数组 `ans`，并将其标记为访问过（赋值为 `INT_MAX`）；

   计算当前方向下的下一步坐标 `(x, y)`；

   若 `(x, y)` 越界或已经访问（值为 `INT_MAX`），则顺时针转向：`di = (di + 1) % 4`；

   按更新后的方向继续移动：`i += DIRS[di][0]`, `j += DIRS[di][1]`。

2. 循环 `m * n` 次，直到遍历完所有元素。
