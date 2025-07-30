# [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)



## 题目

给你一个整数数组 `nums` ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**子数组**是数组中的一个连续部分。

 

**示例 1：**

```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

**示例 2：**

```
输入：nums = [1]
输出：1
```

**示例 3：**

```
输入：nums = [5,4,-1,7,8]
输出：23
```

 

**提示：**

- $1 <= nums.length <= 10^5$
- $-10^4 <= nums[i] <= 10^4$

 

**进阶：**如果你已经实现复杂度为 `O(n)` 的解法，尝试使用更为精妙的 **分治法** 求解。



## 题解

### 解1 前缀和+贪心

- 时间复杂度: O(n)。遍历一遍数组

- 空间复杂度: O(n)。维护了一个preSum，是vector<int>，和原数组具有相同规模

```cpp
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> preSum;
        preSum.push_back(0);
        int ans = INT_MIN, min = INT_MAX, sum = 0; // 前缀和第0号元素为0，则min直接设置为0
        // 问题：min的初始化没有做好
        // 解决：min初始化就为INT_MAX。需要注意的一点是min的判断要在更新sum以前
        // 因为本题存在正负数，因此不能出现min等于自身的情况，这会导致自身-自身=0
        // 这是与买卖股票不同的一点，股价只可能是正的
        for (int a : nums)
        {
            min = sum < min ? sum : min;
            sum += a;
            preSum.push_back(sum);
            int temp = sum - min;
            ans = temp > ans ? temp : ans;
        }
        return ans;
    }
};
```



### 解2

- 时间复杂度：O(n)
- 空间复杂度：O(n)。维护一个dp数组，和nums同规模

```cpp
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
            dp[i] = max(dp[i - 1], 0) + nums[i];
        return *max_element(dp.begin(), dp.end());
        // 或ranges::max(dp)
    }
};
```

- 空间复杂度：优化为O(1)

```cpp
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int dp = 0;
        for (int a : nums)
        {
            dp = max(dp, 0) + a;
            ans = max(ans, dp);
        }
        return ans;
    }
};
```



## points

### 解1

1. 因为这题要求的是连续子数组，该子数组的最大和，也就是一个区间的加和，所以想到可以用前缀和

2. 维护一个前缀和数组preSum，第0号元素为0。然后在遍历nums数组的时候，一边更新preSum，一边根据当前索引的前缀和，以及前面出现前缀和的最小值，来不断更新min，以及ans

   这里注意一点min：min初始化要为INT_MAX，但更新min的值要先于更新preSum，也就是说min要是该索引前面出现的前缀和的最小值，不能包含自身

   这里与买卖股票的区别就是，股价是正的，而本题的数字有负数，因此如果你允许自己-自己的话，就可能导致最后得到的答案为0，而实际上数组里全都是负数



### 解2

1. 考虑用动态规划的方式来做。维护一个dp数组，表示大小与nums一样，表示的是当子区间以nums[i]结尾时，能够达到的最大的加和值

   递推公式为：dp[0]就是nums[0]自身；

   对于i＞0，每次检查i-1的dp值，它是否为负，如果为负，就不取它，dp[i]只取自己的值nums[i]，因为如果加上前面的部分，指挥导致当前dp值更小；

   如果前面的为正，则以自身为结尾的dp值要拼接上前面的部分

2. 这种做法关注点只有以nums[i]结尾的加和值，每一个状态都是由前一个状态推导出来的，而前面的情况是什么，不关心，不用管子区间的起点在哪，只需要一个个递推得到最大加和区间即可

3. 进一步优化，由于每一个状态只与它前面的一个状态唯一相关，而再往前的无关，因此dp数组可以优化为一个变量，只要存储前继的唯一一个值即可。这就大大优化了空间