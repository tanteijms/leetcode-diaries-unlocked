# [739. 每日温度](https://leetcode.cn/problems/daily-temperatures/)



## 题目

给定一个整数数组 `temperatures` ，表示每天的温度，返回一个数组 `answer` ，其中 `answer[i]` 是指对于第 `i` 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 `0` 来代替。

 

**示例 1:**

```
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
```

**示例 2:**

```
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
```

**示例 3:**

```
输入: temperatures = [30,60,90]
输出: [1,1,0]
```

 

**提示：**

- $1 <= temperatures.length <= 10^5$
- `30 <= temperatures[i] <= 100`



## 题解

```cpp
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int a = temperatures[i];
            while (!st.empty() && a >= temperatures[st.top()])
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans[i] = st.top() - i;
            }

            st.push(i);
        }
        return ans;
    }
};
```



## points

1. 暴力，所有元素都一样，n^2

2. 优化：右到左，有更高的峰，可以完全舍弃掉更小的数
   栈顶放最小的，维护一个单调栈。每次放递减的，但是，如果找到了比当前栈顶更大的，那就把小于这个数a的栈顶所有元素都删掉，并push 这个新的数 a。
   始终保证栈单调递减

3. push 的时候，入最上。pop 的时候，从最上拿掉。所以是先进先出，用栈
   记录某个数的时候，把所有小于它的数都去掉，所以维护单调性。
   综上，单调栈

4. review:
   从右到左：先取出来当前遍历到的元素 a，然后拿它去和栈顶进行比较，如果栈顶有元素，那就看和 a 的大小。如果＞a，那么就是我们要找的
   这里注意为了方便定位到数组内部元素的次序关系，栈里存的都是下标，需要元素的时候去原数组里取即可。
   如果栈顶元素比 a 小（或等于）的话，那么就丢弃，因为不需要了
   若＞，则找到答案，把 ans[i]设为这个元素到 a 的距离（这个情况是最后栈不为空，也就是找到了比 a 大的元素）
   而还有一种情况，就是栈遍历完了都没有比 a 大的，那么答案就是 0。不用改，因为初始化的时候直接给 vector<int>  填充了 n 个 0
   之后要把当前元素的下标 push 到栈里。继续维护单调栈