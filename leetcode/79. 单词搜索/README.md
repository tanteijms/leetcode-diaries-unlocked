# [79. 单词搜索](https://leetcode.cn/problems/word-search/)



## 题目

给定一个 `m x n` 二维字符网格 `board` 和一个字符串单词 `word` 。如果 `word` 存在于网格中，返回 `true` ；否则，返回 `false` 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

**示例 1：**

![img](./assets/word2.jpg)

```
输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "ABCCED"
输出：true
```

**示例 2：**

![img](./assets/word-1.jpg)

```
输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "SEE"
输出：true
```

**示例 3：**

![img](./assets/word3.jpg)

```
输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "ABCB"
输出：false
```

 

**提示：**

- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` 和 `word` 仅由大小写英文字母组成

 

**进阶：**你可以使用搜索剪枝的技术来优化解决方案，使其在 `board` 更大的情况下可以更快解决问题？



```cpp
class Solution
{
    vector<pair<int, int>> di = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    // 下 右 上 左

    vector<vector<char>> b;
    int m, n;
    string w;
    int nn;

    bool dfs(int i, int j, int k) // j k记录当前行列
    {
        // 本层及以后的
        // 当前字母可用，选
        if (w[i] == b[j][k])
        {
            if (i == nn - 1)
                return true; // 原来的套路是，给i+1，然后继续dfs
            // 这样的话，的确在结束的时候，递归到的新的，是ok的，恰好满足匹配
            // 但是我在遍历一个点的四个方向的时候，遇到不合法的，我直接不让他递归了
            // 因此不满足

            b[j][k] = '\0';
            for (auto a : di) // 遍历4个方向
            {
                int x = j + a.first;
                int y = k + a.second;
                if (x >= 0 && x < m && y >= 0 && y < n && b[x][y] != '\0')
                {
                    if (dfs(i + 1, x, y))
                    {
                        // 只有有真的，才更新为true
                        // 有了true以后，后面都要一路开绿灯，确保返回到第一层

                        b[j][k] = w[i];
                        return true;
                        // tag只是传递，必须从回溯递归终止的时候传上来
                    }
                }
            }
            b[j][k] = w[i];
        }

        // 不选的话默认就是false，当前字符直接跳过
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        b = board;
        m = board.size();
        n = board[0].size();
        w = word;
        nn = word.size();

        if (m == 0 || n == 0 || w.empty())
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(0, i, j))
                    return true;
            }
        }
        return false;
    }
};
```





## points

1. 问题在于，要像岛屿数量那样考虑，深度优先，但是需要遍历所有的点为开头，这样的才是对的。

   也就是在主循环里，需要写2层for循环

2. 以及如果找到true了直接返回就行，然后无条件逐层向上返回

3. 以及需要对输入进行考虑

   如果行列任意一个为0，就不合法，直接返回

   且输入的word，若为空串，也直接返回了

4. 复盘：

   因为是在一张图里，上下左右四个方向，因此先定义方向数组

   这里注意pair的定义以及相关用法

   定义board的镜像b

   m，n是二维数组的长宽

   w是word的镜像

   nn是w的长度

   定义dfs，需要传入1. 递归的层数 2. 当前的行列index j k

   这里我们不定义递归终止条件了，因为在后面深度优先的时候，我们对于某一个点的四个方向，是直接进行了判断，是否合法，如果不合法，那就直接不dfs下面的，直接continue了。这样的话，如果我们在当时的点已经找到了正确的字符串，那我们在当前的层级直接返回就行。如果还是按照回溯一般的定义，由于根本进入不到nn+1层，因此i根本无法等于nn，这样会失去很多正确答案。

   因此我们直接来判断当前点的字符是否是word当前需要的。如果是的话，那么先判断一下当前i是否已经到了nn-1，也就是当前字符就是word最后一个字符了，那说明找到了正确答案，直接返回true就行了。并且逐级把这个true返回到最上层

   因为当前字符是我们需要的，那么把他标记为'\0'，表示已经用过了，不允许重复的题目

   下面对于当前的点，遍历他的四个方向，从di方向数组里面取出，看看当前是往什么方向走。先进行判断，必须在b的边界范围内，且那个值没有被用，才dfs i+1的。

   dfs i+1的时候，如果找到了，那就先恢复现场，然后直接返回true

   如果没找到，最后也要记得恢复现场

   没找到，就return false

   主函数里面，先对类成员变量进行初始化，然后判断：如果给的矩阵，或者word是空，那就不用比对了，直接return false

   然后按照图的深度优先遍历，需要遍历for m for n，遍历每一个点。但是只要找到一个true的结果，就直接return。否则最后return false

5. 两个优化

   统计字母出现的次数，若word里某个字母的出现的次数小于board里含有的，那么显然不满足，直接return false

   比较开头结尾的字符，谁少从谁开始，这样更快容易停止递归

6. 统计字符用两个哈希表即可

7. 翻转字符串用std::reverse  std::ranges::reverse