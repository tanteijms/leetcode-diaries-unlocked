# [238. 除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/)



## 题目

给你一个整数数组 `nums`，返回 数组 `answer` ，其中 `answer[i]` 等于 `nums` 中除 `nums[i]` 之外其余各元素的乘积 。

题目数据 **保证** 数组 `nums`之中任意元素的全部前缀元素和后缀的乘积都在 **32 位** 整数范围内。

请 **不要使用除法，**且在 `O(n)` 时间复杂度内完成此题。

 

**示例 1:**

```
输入: nums = [1,2,3,4]
输出: [24,12,8,6]
```

**示例 2:**

```
输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]
```

 

**提示：**

- $2 <= nums.length <= 10^5$
- `-30 <= nums[i] <= 30`
- 输入 **保证** 数组 `answer[i]` 在 **32 位** 整数范围内

 

**进阶：**你可以在 `O(1)` 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 **不被视为** 额外空间。）



## 题解

- 时间复杂度: O(n)。遍历三次规模为n的数组

- 空间复杂度: O(n)。用到两个前缀、后缀积的数组，和nums同等规模大小

```cpp
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 记录一个前缀积，一个后缀积数组
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> ans(nums.size());
        int pro = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            pro *= nums[i];
            prefix[i] = pro;
        }
        pro = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            pro *= nums[i];
            suffix[i] = pro;
        }
        ans[0] = suffix[1];
        ans[nums.size() - 1] = prefix[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; i++)
            ans[i] = prefix[i - 1] * suffix[i + 1];
        return ans;
    }
};
```



## points

1. 可以维护两个数组，大小和nums一样，分别记录到该索引位置元素的前缀积 和 后缀积

   之后遍历这两个数组，用i-1的前缀积乘i+1的后缀积就是要求的除了i以外的所有元素的乘积



## 解2

1. 节约空间不用数组的话，就分别遍历，第一次从头开始到n-2的位置，一次累乘pro变量，并错位给ans[i+1]赋pro的值

   第二次遍历的时候逆着来，从n-1号元素开始到1号元素，重置pro后再次一次累乘，错位给[i-1]*=上pro

2. 有一个问题是如果不指定默认值的话，ans所有的初始会被赋为0。这样的话由于第一次遍历没有对ans[0]进行操作，因此ans[0]还是0。到第二次遍历的时候是*=操作，因此会导致出错。所以直接在ans初始化的时候给所有元素赋为1，毕竟是乘积的操作