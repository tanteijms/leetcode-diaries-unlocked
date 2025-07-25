# [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)



## 题目

给你一个整数数组 `nums` 和一个整数 `k` ，请你统计并返回 *该数组中和为 `k` 的子数组的个数* 。

子数组是数组中元素的连续非空序列。

 

**示例 1：**

```
输入：nums = [1,1,1], k = 2
输出：2
```

**示例 2：**

```
输入：nums = [1,2,3], k = 3
输出：2
```

 

**提示：**

- $1 <= nums.length <= 2 * 10^4$
- `-1000 <= nums[i] <= 1000`
- $-10^7 <= k <= 10^7$



## 题解



```cpp
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixCnt;
        prefixCnt[0] = 1; // sum=0前缀和初始值
        int sum = 0, ans = 0;
        for (int a : nums)
        {
            sum += a;
            if (prefixCnt.count(sum - k))
                ans += prefixCnt[sum - k];
            prefixCnt[sum]++;
        }
        return ans;
    }
};
```





## points

1. 滑动窗口不行

2. 前缀和+哈希表

3. 初始化哈希表的时候，需要一个0 1的键值对

   这个虚拟的前缀代表从数组开头开始累加的起点

4. 因为这个数组有正负有0，所以在遍历的时候，维护一个前缀和，即从nums开始到现在所有数的和

   利用哈希表来减少插入和查询的时间

   遍历过程中，先加当前值。然后计算sum-k，不论是正or负or0，去维护的哈希表里查找是否有键是这个sum-k，如果有的话，那么说明：在前面的某个或某几个索引处，有前缀和为sum-k的，而当前索引前缀和为sum，则从前面的某个索引到当前索引，加和的值恰好就是k，满足题意

   因此给答案加上sum-k这个键对应的值，是几就说明有几个这样的索引存在（因为负数的存在，所以前缀和并不一定是递增的）

   之后把当前节点的sum也加入哈希表里。不存在就插入sum 1这个键值对；存在就++