# [48. 旋转图像](https://leetcode.cn/problems/rotate-image/)



## 题目

给定一个 *n* × *n* 的二维矩阵 `matrix` 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在**[ 原地](https://baike.baidu.com/item/原地算法)** 旋转图像，这意味着你需要直接修改输入的二维矩阵。**请不要** 使用另一个矩阵来旋转图像。

 

**示例 1：**

![img](./assets/mat1.jpg)

```
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
```

**示例 2：**

![img](./assets/mat2.jpg)

```
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

 

**提示：**

- `n == matrix.length == matrix[i].length`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`



## 题解

- 时间复杂度：$O(n^2)$。转置的时候遍历了接近一半的数组元素
- 空间复杂度：O(1)。原地进行操作，没有额外空间开销

```cpp
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        for (vector<int> &a : matrix)
            reverse(a.begin(), a.end());
    }
};
```





## points

1. 考虑旋转90°的数学本质

   第j列的会到第j行

   第i行的会到倒数i列，即n-1-i列，这里考虑ij都是从0开始

2. 数学上证明可以通过两次翻转来实现

   首先转置，因为j列的会到j行，所以转置可以很方便地实现

   (i, j)-->(j, i)

   然后需要调整，把列上的i变成n-1-i，显然是一个翻转，reverse函数可以实现

   (j, i)-->(j, n-1-i)

3. 所以进行两步操作即可

   首先行优先遍历i，列只需要遍历到n-1-i=j号元素即可，也就是遍历矩阵的上半个三角就行，然后交换i j   j i

   然后遍历每一列，获取每一行的vector，传入reverse函数，实现翻转