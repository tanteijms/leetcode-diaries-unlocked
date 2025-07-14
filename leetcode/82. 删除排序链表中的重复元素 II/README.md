# [82. 删除排序链表中的重复元素 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/)



## 题目

给定一个已排序的链表的头 `head` ， *删除原始链表中所有重复数字的节点，只留下不同的数字* 。返回 *已排序的链表* 。

 

**示例 1：**

![img](./assets/linkedlist1.jpg)

```
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
```

**示例 2：**

![img](./assets/linkedlist2.jpg)

```
输入：head = [1,1,1,2,3]
输出：[2,3]
```

 

**提示：**

- 链表中节点数目在范围 `[0, 300]` 内
- `-100 <= Node.val <= 100`
- 题目数据保证链表已经按升序 **排列**



## 题解

- 时间复杂度：O(n)。虽然是嵌套循环，但是循环条件的变量始终是cur，因此最终是cur对全部结点的遍历
- 空间复杂度：O(1)。仅用到若干变量

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur->next && cur->next->next) // 因为cur是要删除的前一个结点
        // 每次都来处理的是它下一个，以及下下一个
        // 如果总结点数为0，则cur是dummy，不会错误
        {
            int val = cur->next->val; // 记录这个可能重复的val，否则后面删除以后，没办法与新的值进行比对
            // 因此要取它next的val
            if (cur->next->next->val == val)
            {
                while (cur->next && cur->next->val == val)
                {
                    ListNode *pre = cur->next;
                    cur->next = cur->next->next; // 修改cur，来删掉cur的下一个
                    delete pre; // 目前没删掉第一个重复的，只是删掉了后面的多余的
                }
            }
            else // 不相等，则往下一个走
                cur = cur->next;
        }
        return dummy.next; // 因为有可能头结点被删掉了
    }
};
```





## points

1. 因为需要删除所有的重复的元素，因此可能要删掉头结点，因此需要dummy，防止混乱
1. 每次外层大循环记录下当前需要进行确认是否删除的val，如果有重复的，则从第一个该val值开始删，所以是cur->next