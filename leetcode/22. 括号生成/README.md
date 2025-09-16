# [22. 括号生成](https://leetcode.cn/problems/generate-parentheses/)



## 题目

数字 `n` 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

 

**示例 1：**

```
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```

**示例 2：**

```
输入：n = 1
输出：["()"]
```

 

**提示：**

- `1 <= n <= 8`



## 题解

```cpp
class Solution
{
    vector<string> ans;
    vector<char> path;
    int nn;

    void dfs(int i, int le, int ri) // left表示前面 ( 的个数
    {
        if (i == 2 * nn)
        {
            string s(path.begin(), path.end());
            ans.emplace_back(s);
            return;
        }

        // ( 最多nn个，用left来判断
        if (le < nn)
        {
            path.emplace_back('(');
            dfs(i + 1, le + 1, ri);
            path.pop_back();
        }

        if (ri < le) // ( 要比 ) 多，才可以加 )
        {
            path.emplace_back(')');
            dfs(i + 1, le, ri + 1);
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        nn = n;
        dfs(0, 0, 0);
        return ans;
    }
};
```



## points

1. 仍然是回溯的套路，此次的判断在于，对于目前的路径path，加入什么是合法的。显然()是成对出现的，且最多为各n个。因此每次dfs的时候判断，如果le个数小于n，那么可以加 ( ；若ri个数小于le，那么可以加 )

2. 复盘：

   定义答案数组ans，内部存string

   定义分支答案path，内部存char。在添加到ans的时候，用string的构造函数，传入char的迭代器的范围，这样自动转化为string

   定义dfs函数，传入i当前总个数，le左括号个数，ri右括号个数。当然i可以用le+ri代替。这里为了和回溯套路对齐，故多用一个变量i，对于解题影响不大

   终止条件，当括号总数为2倍n时，添加答案后return

   下面对于当前分支，是否添加()，判断如果le个数小于n，那就可以加(；若ri个数小于le，那就可以加)

   主函数初始化nn

   然后调dfs(0,0,0)即可