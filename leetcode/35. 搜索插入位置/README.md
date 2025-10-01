# [35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position/)



## 题目

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 `O(log n)` 的算法。

 

**示例 1:**

```
输入: nums = [1,3,5,6], target = 5
输出: 2
```

**示例 2:**

```
输入: nums = [1,3,5,6], target = 2
输出: 1
```

**示例 3:**

```
输入: nums = [1,3,5,6], target = 7
输出: 4
```

 

**提示:**

- $1 <= nums.length <= 10^4$
- $-10^4 <= nums[i] <= 10^4$
- `nums` 为 **无重复元素** 的 **升序** 排列数组
- $-10^4 <= target <= 10^4$



## 题解

- 时间复杂度: O(logN)。二分对于一个nums.size()=N的数组，每次缩小一般的范围，则取以2为底的对数

- 空间复杂度: O(1)。仅用到若干变量。

```cpp
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int le = 0, ri = nums.size() - 1;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                ri = mid - 1;
            else // nums[mid]<target
                le = mid + 1;
        }
        // 退出循环的前一刻：le=ri=mid，若=，就是le
        // 若> 也应该刚好插入到这个位置，ri--了，则是le
        // 若< 说明小了，要插入到下一个位置，刚好le++了，则直接就是le
        return le;
    }
};
```



## points

1. 复盘

   二分，我一直用的闭区间，循环条件是le<=ri

   主要考虑最后如何确定答案值即可。如果直接return mid，就是target对应索引；若最后是从le=ri=mid退出的，那么就考虑不同情况。最后答案是le

   若> 也应该刚好插入到这个位置，ri--了，则是le

   若< 说明小了，要插入到下一个位置，刚好le++了，则直接就是le