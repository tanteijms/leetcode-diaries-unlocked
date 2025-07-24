# [1. 两数之和](https://leetcode.cn/problems/two-sum/)



## 题目

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。

 

**示例 1：**

```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```
输入：nums = [3,3], target = 6
输出：[0,1]
```

 

**提示：**

- $2 <= nums.length <= 10^4$
- $-10^9 <= nums[i] <= 10^9$
- $-10^9 <= target <= 10^9$
- **只会存在一个有效答案**



## 题解

### 解1

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 不能O(n^2)
        unordered_map<int, vector<int>> allNums;
        for (int i = 0; i < nums.size(); i++)
            allNums[nums[i]].push_back(i);
        for (int i = 0; i < nums.size(); i++)
        {
            // 取出来另一个加数对应在map里的值vector
            vector<int> a = allNums[target - nums[i]];
            if (!a.empty()) // 非空
            {
                // if(target!=2*nums[i])
                //    return {i, a[0]};
                for (int b : a)
                {
                    if (b != i)
                        return {i, b};
                }
            }
        }

        return {};
    }
};
```



### 解2

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = target - nums[i];
            if (map.count(a))
                return {map[a], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
```





## points

### 解1

1. 首先遍历一遍数组，将所有元素作为键，而值是一个vector，存放该元素出现的所有位置索引值

2. 第二遍遍历数组，每次取一个元素值，然后用target-nums[i]得到另一个加数，再把这个加数传入到哈希表里，作为键去查找值

   如果值对应的vector为空，说明原数组不存在这个加数，能够满足相加=target

   而如果对应vector非空，说明原数组是存在这个数的，我们可以去找到一个对应的索引

   但是这里还有一种情况，那就是如自身是3，target=6，如果原数组只有一个3，因为题目规定了不能重复用同一个元素，因此记录的这个vector，还需要去查看里面的值，如果能够找到一个和当前索引，即i，不相等的另一个索引，那么说明3在原数组出现了两次及以上，因此可以返回

   如果不是3+3=6这样的情况，那么可以直接返回

3. 注：2.中看似用到了第二层内层循环，但是实际上循环的次数至多是2

   - 如果i是vector的第一个元素，那么找到第二个元素就return了
   - 如果i不是第一个元素，那么找到第一个元素就直接return了

   因此并不是$O(n^2)$的时间复杂度



### 解2

1. 遍历的时候，直接在哈希表里查找target-nums[i]。如果找到了，立即返回结果。如果没找到，就把当前nums[i]和下标存入哈希表

2. 这样能够解决如果3+3=6，直接返回了

   而如果tartget不是6，那么更新这个3也不会影响，因为只会用到3的索引一次，存一个就够了