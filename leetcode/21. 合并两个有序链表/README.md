# [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)



## 题目

将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

**示例 1：**

![img](./assets/merge_ex1.jpg)

```
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
```

**示例 2：**

```
输入：l1 = [], l2 = []
输出：[]
```

**示例 3：**

```
输入：l1 = [], l2 = [0]
输出：[0]
```

 

**提示：**

- 两个链表的节点数目范围是 `[0, 50]`
- `-100 <= Node.val <= 100`
- `l1` 和 `l2` 均按 **非递减顺序** 排列



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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *pre = &dummy, *cur1 = list1, *cur2 = list2;

        // cur1和cur2是遍历过程中新的要接入的结点，分别在list和list2里
        // pre及以前是已经排序好的
        while (cur1 && cur2)
        {
            if (cur1->val >= cur2->val)
            {
                pre->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                pre->next = cur1;
                cur1 = cur1->next;
            }
            pre = pre->next;
        }

        pre->next = cur1 ? cur1 : cur2;
        return dummy.next;
    }
};
```





## points

1. 因为可能传入的list1和list2有空的，为了防止多余的判断，统一用哨兵节点处理

   取pre为dummy的地址值，这个pre始终是已排序好的最末尾

2. 注意退出循环后要把剩余的部分接上，因为退出while循环的条件是任意一个cur为空，而另一个可能还有

3. 最后return dummy.next即可