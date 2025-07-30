# [189. 轮转数组](https://leetcode.cn/problems/rotate-array/)



## 题目

给定一个整数数组 `nums`，将数组中的元素向右轮转 `k` 个位置，其中 `k` 是非负数。

 

**示例 1:**

```
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
```

**示例 2:**

```
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
```

 

**提示：**

- $1 <= nums.length <= 10^5$
- $-2^{31} <= nums[i] <= 2^{31} - 1$
- $0 <= k <= 10^5$

 

**进阶：**

- 尽可能想出更多的解决方案，至少有 **三种** 不同的方法可以解决这个问题。
- 你可以使用空间复杂度为 `O(1)` 的 **原地** 算法解决这个问题吗？



## 题解

- 时间复杂度: O(n)。不论是assign复制还是emplace_back()一个个添加，都是O(n)的

- 空间复杂度: O(n)。创建了一个临时变量temp，规模和nums一样

```cpp
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> temp(nums.size());
        k %= nums.size();
        temp.assign(nums.end() - k, nums.end());
        for (int i = 0; i < nums.size() - k; i++)
            temp.emplace_back(nums[i]);
        nums.assign(temp.begin(),temp.end());
    }
};
```



## points

1. 思路和字符串轮转使用子串拼接的方法一样，创建一个临时数组，把后半部分先填进去，再把前半部分填进去
2. 注意先给k模一个nums.size()，除去重复的轮转次数
3. 把倒数k个数填入temp里，之后再把前面的nums.size()-k个数接到后面



## 解2

1. 举个例子： 1 2 3 4 5 6 7  轮转3次，变成

   5 6 7 1 2 3 4

   效果上看，可以拆解为 先整体反转，再前后分别反转，界限为k

   1 2 3 4 5 6 7

   7 6 5 || 4 3 2 1

   5 6 7 || 1 2 3 4

   因此原地的话，可以用std::reverse来实现，是原地反转的

2. 如果自己写reverse的实现逻辑的话，即双指针交换，会很慢，不知道力扣为啥

下面分别为自己写底层逻辑和直接用stl封装好的库函数

```cpp
class Solution
{
    void reverse_vector(vector<int> &a, int begin, int end)
    {
        for (int i = begin, j = end; i < j; i++, j--)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse_vector(nums, 0, nums.size() - 1); // 闭区间！
        reverse_vector(nums, 0, k - 1);
        reverse_vector(nums, k, nums.size() - 1);
    }
};
```

```cpp
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums.begin(), nums.end()); // 左闭右开
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```

