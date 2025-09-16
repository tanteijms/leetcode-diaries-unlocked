# [39. 组合总和](https://leetcode.cn/problems/combination-sum/)



## 题目

给你一个 **无重复元素** 的整数数组 `candidates` 和一个目标整数 `target` ，找出 `candidates` 中可以使数字和为目标数 `target` 的 所有 **不同组合** ，并以列表形式返回。你可以按 **任意顺序** 返回这些组合。

`candidates` 中的 **同一个** 数字可以 **无限制重复被选取** 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 `target` 的不同组合数少于 `150` 个。

 

**示例 1：**

```
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
```

**示例 2：**

```
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
```

**示例 3：**

```
输入: candidates = [2], target = 1
输出: []
```

 

**提示：**

- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`
- `candidates` 的所有元素 **互不相同**
- `1 <= target <= 40`



```cpp
class Solution
{
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> can;
    int n;
    int t;

    void dfs(int i, int sum)
    {
        // 终止条件1，找到了目标和，就立马加入path，并返回此次回溯
        // 因为数值均为正，后面找到一定超过当前值
        if (sum == t)
        {
            ans.emplace_back(path);
            return;
        }

        // 终止条件2：越界，或超出目标值，及时停止回溯，当前分支没有结果
        if (i == n || sum > t)
            return;

        // 选当前i
        path.emplace_back(can[i]);
        dfs(i, sum + can[i]); // 因为允许重复选择，所以当前i不增加
        path.pop_back();

        // 不选当前i
        dfs(i + 1, sum);
    }

public:
    vector<vector<int>>
    combinationSum(vector<int> &candidates, int target)
    {
        n = candidates.size();
        t = target;
        can = candidates;
        dfs(0, 0);
        return ans;
    }
};
```



## points

1. 虽然有一个加和为target的限定，但是回溯利用递归，因此这样的条件限定，在递归终止判断的时候进行即可，因为本身回溯就是一种穷举试错的算法，最后错了就错了，回溯即可，不添加答案。

2. 复盘：

   定义全局答案ans

   定义某一条分支的答案path

   定义全局can，用来copy一份传入的candidates，方便递归时拿到该数组

   定义全局n，为can的长度

   定义t，为target的副本

   定义dfs函数：此题加了加和的限制，因此除了传入回溯深度的i，还需要加一个sum，用来表示当前路径记录的值的加和，来判断

   首先定义递归终止条件：

   1. sum==t，说明找到了一个有效答案，记录path到ans，返回
   2. i==n，或加和的sum太大了，已经超出了t。此时答案已经无效了，这就是回溯算法试到的错，直接return即可

   接下来是处理当前节点。可以有两种情况：选或不选

   其中选甚至可以选多次，没有限制，因此先加入到path后面，然后传入dfs的时候，i不动，只给sum+当前can[i]值。回溯后恢复现场

   要么就是完全不选，直接dfs(i+1,sum) sum不变

   主函数的时候，初始化n t can，然后直接dfs(0,0)即可
