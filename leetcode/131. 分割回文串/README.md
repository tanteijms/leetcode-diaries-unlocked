# [131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/)



## 题目

给你一个字符串 `s`，请你将 `s` 分割成一些 子串，使每个子串都是 **回文串** 。返回 `s` 所有可能的分割方案。

 

**示例 1：**

```
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
```

**示例 2：**

```
输入：s = "a"
输出：[["a"]]
```

 

**提示：**

- `1 <= s.length <= 16`
- `s` 仅由小写英文字母组成



```cpp
class Solution
{
    vector<vector<string>> ans;
    vector<string> path;
    string ss;
    int n;

    bool is_huiwen(string s) // 双指针判断当前子串是否是回文串
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void dfs(int i, int start) // start是当前字串开始的位置
    {
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }

        // 当前，不选，那就不分割
        if (i < n - 1)
        {
            dfs(i + 1, start);
        }

        // 当前，选择，那就分割
        // 判断一下是否是回文串
        string a = ss.substr(start, i - start + 1);
        if (is_huiwen(a))
        {
            path.emplace_back(a);
            dfs(i + 1, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        ss = s;
        n = s.size();
        if (s.empty())
            return {};
        dfs(0, 0);
        return ans;
    }
};
```



## points

1. 子集型回溯

2. 假设每两个字符之间有逗号，选不选逗号，就是子集型

3. 从输入的视角看，选不选逗号。选的话，那当前i位置恰好就是上一个子串结束的位置

4. 传入一个start，表示这时候处理字串的起点。如果一直不分割，那就是最开始的。若分割了，那么就从i+1为新的start。每一条不同分支的路径上，选择逗号不同，那么分得的字串是不一样的。

5. reverse判断是否是回文，最坏效率和双指针一样，但是双指针提前找到不一样的字符就直接退出了，实际上更快

6. 若i=n-1，必须分割

   此时我们已经在了最后一个字符的后面，那么当前子串一定要分割，但可以不是回文的，不用加入到答案里。

   处理机制为，假设串abacd，当前在c

7. 复盘：

   定义答案数组ans，每一个元素都是一个vector<string\>。因为每一条path实际上都是分割好的回文子串，代表我们此次分割的方案。子串又都是string的

   定义每次分割方法得到的一个path，存放子串string。这些子串合起来就是完整字符串。我们实际上最后要求得的是分割子串的方法，可能后面很多都是单独的一个字符，但只要前面的子串是回文的，那么就可以算作不同的分割方法

   定义s的镜像ss

   定义n s的长度

   定义辅助函数is_huiwen，用双指针两头向中间逼近来判断是否回文。这比reverse更快

   定义回溯dfs，传入参数为i递归层数，以及start当前子串开始的位置

   定义终止条件，当i==n时，说明此时是一种分割方案的结尾，那么就添加到ans里并return

   本题是以隐形的,为核心算法的，也就是我们把每两个字符之间，都看作有,，这样的话，通过枚举不同的选逗号的方式，恰好就得到了不同的分割方案。注意的是n-1号,一定要选择，规定。这相当于最后一个字符的后面一个,

   对于递归层数i，当前指示的这个,，两种方案

   若不选，则直接跳过，前往i+1。但是注意n-1的时候不可以不选

   若选，则分割得到一个新的子串，是从start开始到当前i为末尾的一个字符串，我们将他分割出来，用sting的substr函数

   下面进行判断，如果当前的子串是回文的话，那么就把他加入到path里，并进行dfs(i+1)。注意的是start此时需要重置，变成i+1。之后回溯回来以后，要恢复现场。

   这里我们可以看到，即便选了当前逗号，如果这个子串不是回文的，也会自动停止，也就是自动进行了剪枝。这样的话能够提高效率。

   主函数里进行ss和n的初始化，先判断s是否为空，若为空直接返回空。然后从dfs(0,0)开始，得到ans

   

   