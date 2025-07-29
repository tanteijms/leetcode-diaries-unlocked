# [303. 区域和检索 - 数组不可变](https://leetcode.cn/problems/range-sum-query-immutable/)



## 题目

给定一个整数数组  `nums`，处理以下类型的多个查询:

1. 计算索引 `left` 和 `right` （包含 `left` 和 `right`）之间的 `nums` 元素的 **和** ，其中 `left <= right`

实现 `NumArray` 类：

- `NumArray(int[] nums)` 使用数组 `nums` 初始化对象
- `int sumRange(int i, int j)` 返回数组 `nums` 中索引 `left` 和 `right` 之间的元素的 **总和** ，包含 `left` 和 `right` 两点（也就是 `nums[left] + nums[left + 1] + ... + nums[right]` )

 

**示例 1：**

```
输入：
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
输出：
[null, 1, -1, -3]

解释：
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
```

 

**提示：**

- $1 <= nums.length <= 10^4$
- $-10^5 <= nums[i] <= 10^5$
- `0 <= i <= j < nums.length`
- 最多调用 $10^4$ 次 `sumRange` 方法



## 题解

- 时间复杂度: O(n)。第一次初始化需要遍历nums数组；但后续的每次查找都是 O(1) 的

- 空间复杂度: O(n)。额外用到了一个和nums数组同数量级大小的preSum

```cpp
class NumArray
{
    vector<int> preSum;

public:
    NumArray(vector<int> &nums)
    {

        int sum = 0;
        preSum.push_back(0); // 第一个前缀和是0，用来计算如果left=0的情况
        // 只有前面保留一个0，才能计算从首个元素开始的加和
        for (int a : nums)
        {
            sum += a;
            preSum.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```





## points

1. 本题由于需要的对一个数组进行多次的范围查询，如果每次查询都去套用循环，时间开销很大。因此在初始化数组的时候维护一个数组各个索引的前缀和，即从第0号元素开始到该索引元素所有的加和，需要什么范围的只需要二者进行相减即可

2. 类内维护一个preSum的vector<int>，在调用构造函数的时候初始化这个数组，首先在preSum的第0号元素存入0，用来计算如果left是0，则计算的就是某个索引的前缀和，因此可以直接减去这个0，得到答案

   之后就是循环整个nums数组，并不断加和得到
   
3. 初始化记录前缀和数组完成以后，return preSum[right+1]-preSum[left]即可得到任意区间上的加和