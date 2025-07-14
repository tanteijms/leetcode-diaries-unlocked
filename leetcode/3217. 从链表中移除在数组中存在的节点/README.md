# [3217. 从链表中移除在数组中存在的节点](https://leetcode.cn/problems/delete-nodes-from-linked-list-present-in-array/)



## 题目

给你一个整数数组 `nums` 和一个链表的头节点 `head`。从链表中**移除**所有存在于 `nums` 中的节点后，返回修改后的链表的头节点。

 

**示例 1：**

**输入：** nums = [1,2,3], head = [1,2,3,4,5]

**输出：** [4,5]

**解释：**

**![img](./assets/linkedlistexample0.png)**

移除数值为 1, 2 和 3 的节点。

**示例 2：**

**输入：** nums = [1], head = [1,2,1,2,1,2]

**输出：** [2,2,2]

**解释：**

![img](./assets/linkedlistexample1.png)

移除数值为 1 的节点。

**示例 3：**

**输入：** nums = [5], head = [1,2,3,4]

**输出：** [1,2,3,4]

**解释：**

**![img](./assets/linkedlistexample2.png)**

链表中不存在值为 5 的节点。

 

**提示：**

- $1 <= nums.length <= 10^5$
- $1 <= nums[i] <= 10^5$
- `nums` 中的所有元素都是唯一的。
- 链表中的节点数在 $[1, 10^5]$ 的范围内。
- $1 <= Node.val <= 10^5$
- 输入保证链表中至少有一个值没有在 `nums` 中出现过。



## 题解

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_map<int, int> freq;
        for (int a : nums)
            freq[a]++;

        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur->next)
        {
            if (freq[cur->next->val])
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};
```





## points

1. 为了避免多次重复遍历，可以只遍历一次链表，而把数组存为哈希表，这样每次对单个结点，去哈希O(1)查找，这样可以很快
2. 在我delete掉后，系统（或者自动测试器） **free 一整条链表**，于是就出现了 **二次释放、访问已释放区域** 的问题